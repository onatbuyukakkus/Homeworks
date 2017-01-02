#ifndef __aoa_jpeg_h__
#define __aoa_jpeg_h__

typedef double COLOR[3];
typedef unsigned char uchar;
typedef uchar UCOLOR[3];

void write_jpeg(const char *filename, UCOLOR **image, int width, int height);
void read_jpeg(const char *filename, UCOLOR **image, int *width, int *height);
void read_jpeg_header(const char *filename, int *width, int *height);

#endif //__aoa_jpeg_h__
