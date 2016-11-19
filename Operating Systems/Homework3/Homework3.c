/*
 * 
 * 
 * 
 * 
 * */

#define FUSE_USE_VERSION 30

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fuse.h>
#include <libgen.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <gdbm.h>


int MAX_PATH_LENGTH =  PATH_MAX;  // can be used if you want to use a fixed array for paths
int MAX_CONTENT_LENGTH = 10*1024*1024;  // you can assume this maximum content length

GDBM_FILE dbf;
char* db;

typedef struct filecontent {
   char type;
   off_t size;
   uid_t user;
   gid_t group;
   mode_t permissions;
   time_t atime;
   time_t mtime;
   time_t ctime;
   char content[0];
} filecontent;
// struct filecontent *ptr = (struct filecontent *)malloc(sizeof filecontent +  whatever_is_needed);

/** Get file attributes.
 *
 * Similar to stat().  The 'st_dev' and 'st_blksize' fields are
 * ignored.  The 'st_ino' field is ignored except if the 'use_ino'
 * mount option is given.
 */
int hw3_getattr(const char *path, struct stat *statbuf)
{
    memset(statbuf, 0, sizeof(struct stat));
    if(dbf) {
        datum key={(char*) path,strlen(path)+1};
        datum value=gdbm_fetch(dbf,key);
        if(value.dsize != 0) {
            filecontent* fcontent = (filecontent*) (value.dptr);
            statbuf->st_uid=fcontent->user;
            statbuf->st_gid=fcontent->group;
            statbuf->st_size=fcontent->size;
            statbuf->st_atime=fcontent->atime;
            statbuf->st_mtime=fcontent->mtime;
            statbuf->st_ctime=fcontent->ctime;
            if(fcontent->type=='D') statbuf->st_mode=(S_IFDIR | (fcontent->permissions));
            else if(fcontent->type=='R') statbuf->st_mode=(S_IFREG | (fcontent->permissions));
            else if(fcontent->type=='L') statbuf->st_mode=(S_IFLNK | (fcontent->permissions));
        }
    }
    return 0;
}

/** Read the target of a symbolic link
 *
 * The buffer should be filled with a null terminated string.  The
 * buffer size argument includes the space for the terminating
 * null character.  If the linkname is too long to fit in the
 * buffer, it should be truncated.  The return value should be 0
 * for success.
 */
int hw3_readlink(const char *path, char *link, size_t size)
{
    return 0;
}

/** Create a file node
 *
 * There is no create() operation, mknod() will be called for
 * creation of all non-directory, non-symlink nodes.
 */
int hw3_mknod(const char *path, mode_t mode, dev_t dev)
{
    return 0;
}

/** Create a directory */
int hw3_mkdir(const char *path, mode_t mode)
{
    return 0;
}

/** Create a symbolic link */
int hw3_symlink(const char *path, const char *link)
{
    return 0;
}

/** Change the permission bits of a file */
int hw3_chmod(const char *path, mode_t mode)
{
    datum temp;
    int res;
    if(dbf) {
        datum key={(char*) path,strlen(path)+1};
        datum value=gdbm_fetch(dbf,key);
        datum temp=gdbm_fetch(dbf,key);
        if(value.dsize != 0) {
            filecontent* fcontent = (filecontent*) (value.dptr);
            fcontent->permissions=mode;
            temp.dptr=(char *) fcontent;
            res=gdbm_store(dbf, key,temp, GDBM_REPLACE);
        }
    }
    return res;
}

/** Change the owner and group of a file */
int hw3_chown(const char *path, uid_t uid, gid_t gid)
{
    datum temp;
    int res;
    if(dbf) {
        datum key={(char*) path,strlen(path)+1};
        datum value=gdbm_fetch(dbf,key);
        datum temp=gdbm_fetch(dbf,key);
        if(value.dsize != 0) {
            filecontent* fcontent = (filecontent*) (value.dptr);
            if(uid!=(unsigned int) -1) {
              fcontent->user = uid;
            }
            if(gid!=(unsigned int) -1) {
              fcontent->group = gid; 
            }
            temp.dptr=(char *) fcontent;
            res=gdbm_store(dbf, key,temp, GDBM_REPLACE);
        }
    }
    return res;
}

/** Change the access and/or modification times of a file */
int hw3_utime(const char *path, struct utimbuf *ubuf)
{
    datum temp;
    int res;
    if(dbf) {
        datum key={(char*) path,strlen(path)+1};
        datum value=gdbm_fetch(dbf,key);
        datum temp=gdbm_fetch(dbf,key);
        if(value.dsize != 0) {
            filecontent* fcontent = (filecontent*) (value.dptr);
            fcontent->atime=ubuf->actime;
            fcontent->mtime=ubuf->modtime;
            temp.dptr=(char *) fcontent;
            res=gdbm_store(dbf, key,temp, GDBM_REPLACE);
        }
    }
    return res;
}

/** File open operation
 *
 * No creation, or truncation flags (O_CREAT, O_EXCL, O_TRUNC)
 * will be passed to open().  Open should check if the operation
 * is permitted for the given flags.  Optionally open may also
 * return an arbitrary filehandle in the fuse_file_info structure,
 * which will be passed to all file operations.
 *
 * Changed in version 2.2
 */
int hw3_open(const char *path, struct fuse_file_info *fi)
{
    return 0;
}

/** Read data from an open file
 *
 * Read should return exactly the number of bytes requested except
 * on EOF or error, otherwise the rest of the data will be
 * substituted with zeroes.  An exception to this is when the
 * 'direct_io' mount option is specified, in which case the return
 * value of the read system call will reflect the return value of
 * this operation.
 *
 * Changed in version 2.2
 */
int hw3_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi)
{
    if(dbf) {
        datum key={(char*) path,strlen(path)+1};
        datum value=gdbm_fetch(dbf,key);
        if(value.dsize != 0) {
            filecontent* fcontent = (filecontent*) (value.dptr);
            if(offset < strlen(fcontent->content)) {
                if(offset+size>strlen(fcontent->content)) {
                    size = strlen(fcontent->content);
                    size -= offset;
                }
                memcpy(buf, fcontent->content+offset, size);
            }
            else {
                size=0;
            }   
        }
    }
    return size;
}

/** Write data to an open file
 *
 * Write should return exactly the number of bytes requested
 * except on error.  An exception to this is when the 'direct_io'
 * mount option is specified (see read operation).
 *
 * Changed in version 2.2
 */
int hw3_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi)
{
    return 0;
}

/** Release an open file
 *
 * Release is called when there are no more references to an open
 * file: all file descriptors are closed and all memory mappings
 * are unmapped.
 *
 * For every open() call there will be exactly one release() call
 * with the same flags and file descriptor.  It is possible to
 * have a file opened more than once, in which case only the last
 * release will mean, that no more reads/writes will happen on the
 * file.  The return value of release is ignored.
 *
 * Changed in version 2.2
 */
int hw3_release(const char *path, struct fuse_file_info *fi)
{
    return 0;
}

/** Open directory
 *
 * This method should check if the open operation is permitted for
 * this  directory
 *
 * Introduced in version 2.3
 */
int hw3_opendir(const char *path, struct fuse_file_info *fi)
{
    return 0;
}

/** Read directory
 *
 * This supersedes the old getdir() interface.  New applications
 * should use this.
 *
 * The filesystem may choose between two modes of operation:
 *
 * 1) The readdir implementation ignores the offset parameter, and
 * passes zero to the filler function's offset.  The filler
 * function will not return '1' (unless an error happens), so the
 * whole directory is read in a single readdir operation.  This
 * works just like the old getdir() method.
 *
 * 2) The readdir implementation keeps track of the offsets of the
 * directory entries.  It uses the offset parameter and always
 * passes non-zero offset to the filler function.  When the buffer
 * is full (or an error happens) the filler function will return
 * '1'.
 *
 * Introduced in version 2.3
 */
int hw3_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi)
{

  if(dbf) {
    datum key={(char*) path,strlen(path)+1};
		datum value=gdbm_fetch(dbf,key);
        if(value.dsize != 0) {
            filecontent* fcontent = (filecontent*) (value.dptr);
            char *token;
            token = strtok(fcontent->content, "/");
            while(token!=NULL) {
                filler(buf, token, NULL, 0);
                token = strtok(NULL, "/");
            }
        }
    }
    return 0;
}

/** Release directory
 *
 * Introduced in version 2.3
 */
int hw3_releasedir(const char *path, struct fuse_file_info *fi)
{
    return 0;
}

/**
 * Initialize filesystem
 *
 * The return value will passed in the private_data field of
 * fuse_context to all file operations and as a parameter to the
 * destroy() method.
 *
 * Introduced in version 2.3
 * Changed in version 2.6
 */
void* hw3_init(struct fuse_conn_info *conn)
{
    dbf=gdbm_open(db,4096,GDBM_WRCREAT,0777,NULL);
    return NULL;
}

/**
 * Clean up filesystem
 *
 * Called on filesystem exit.
 *
 * Introduced in version 2.3
 */
void hw3_destroy(void *userdata)
{
    gdbm_close(dbf);
}

/**
 * Check file access permissions
 *
 * This will be called for the access() system call.  If the
 * 'default_permissions' mount option is given, this method is not
 * called.
 *
 * This method is not called under Linux kernel versions 2.4.x
 *
 * Introduced in version 2.5
 */
int hw3_access(const char *path, int mask)
{
    return 0;
}

struct fuse_operations hw3_oper = {
  .getattr = hw3_getattr,
  .readlink = hw3_readlink,
  .mknod = hw3_mknod,
  .mkdir = hw3_mkdir,
  .symlink = hw3_symlink,
  .chmod = hw3_chmod,
  .chown = hw3_chown,
  .utime = hw3_utime,
  .open = hw3_open,
  .read = hw3_read,
  .write = hw3_write,
  .release = hw3_release,
  .opendir = hw3_opendir,
  .readdir = hw3_readdir,
  .releasedir = hw3_releasedir,
  .init = hw3_init,
  .destroy = hw3_destroy,
  .access = hw3_access,
};

void hw3_usage()
{
    fprintf(stderr, "usage:  hw3 [FUSE and mount options] gdbmFile mountPoint\n");
    abort();
}

char* dbFile = NULL;
int main(int argc, char *argv[])
{
    int fuse_stat;
    
    dbFile = argv[1];
    db = dbFile;

    fuse_stat = fuse_main(argc-1, argv+1, &hw3_oper, NULL);
    
    return fuse_stat;
}
