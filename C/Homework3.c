#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct account
{
	char name[10];	
	int activation; /*1'se inaktif, 0'sa aktif*/
	int id;
	int followerCounter;
	int messageListCounter;
	int sentMessageListCounter;
	int sentMessages[1000];
	int messages[1000];
	int followers[1000];
	struct account *next;
};

int main()
{
	int i,j,k,l,n;
	char function[9];
	char user1[11];
	char user2[11];
	char name[11];
	int *array;
	int len,len2,len3,temp,temp2;
	int idcounter=1;
	int counter=0;
	int newid;
	int messagecounter=0;
	int messageNumber;
	int newMessage;
	FILE *input;
	FILE *output;
	input=fopen("input.txt","r");
	output=fopen("output.txt","w");
	struct account *first=malloc(sizeof(struct account));
	while(1)
	{
		if(feof(input)) break;		
		fscanf(input,"%s",function);	
		if(strcmp(function,"ADD")==0)
		{
			struct account *new=malloc(sizeof(struct account));
			struct account *trial;
			fscanf(input,"%s",new->name);		
			for(trial=first;trial->next!=NULL;trial=trial->next);		
			new->id=idcounter;			
			trial->next=new;
			idcounter++;
		}
		if(strcmp(function,"FOLLOW")==0)
		{
			struct account *trial;
			fscanf(input, "%s %s", user1, user2);
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{							
				if(strcmp(user1,trial->name)==0)
				{				
					newid=trial->id;
				}
			}
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{
				if(strcmp(user2,trial->name)==0)
				{
					trial->followers[(trial->followerCounter)]=newid;
					(trial->followerCounter)++;
				}
			}
		}
		if(strcmp(function,"SEND")==0)
		{
			struct account *trial;
			struct account *trial2;
			fscanf(input, "%s", user1);
			messagecounter++;
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{				
				if(strcmp(user1,trial->name)==0)
				{
					trial->messages[trial->messageListCounter++]=messagecounter;
					array=trial->followers;
					trial->sentMessages[trial->sentMessageListCounter++]=messagecounter;
					for(trial2=first->next;trial2!=NULL;trial2=trial2->next)
					{
						for(j=0;j<trial->followerCounter;j++)
						{
							if(trial2->id==array[j] && trial2->activation==0)
							{
								trial2->messages[trial2->messageListCounter++]=messagecounter;
							}
						}
					}
				}	
			}
		}
		if(strcmp(function,"INACTIVE")==0)
		{
			struct account *trial;			
			fscanf(input, "%s", user1);
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{
				if(strcmp(user1,trial->name)==0)
				{
					trial->activation=1;
				}			
			}		
		}
		if(strcmp(function,"ACTIVE")==0)
		{
			struct account *trial;			
			fscanf(input, "%s", user1);
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{
				if(strcmp(user1,trial->name)==0)
				{
					trial->activation=0;
				}			
			}		
		}
		if(strcmp(function,"RESEND")==0)
		{
			struct account *trial;
			fscanf(input,"%s",user1);
			fscanf(input,"%d",&messageNumber);
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{
				if(strcmp(user1,trial->name)==0)
 				{					
					newMessage=trial->messages[(trial->messageListCounter)-messageNumber];						
					trial->messages[trial->messageListCounter++]=newMessage;
					for(i=0;i<trial->followerCounter;i++)
					{
						array[i]=trial->followers[i];
						len=trial->followerCounter;
					}				
				}
			}
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{
				for(j=0;j<len;j++)
				{
					if(trial->id==array[j] && trial->activation==0)
					{
						trial->messages[trial->messageListCounter++]=newMessage;
					}
				}
			}
		}
		if(strcmp(function,"UNFOLLOW")==0)
		{	
			struct account *trial;
			struct account *trial2;
			fscanf(input, "%s %s", user1, user2);
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{			
				if(strcmp(user1,trial->name)==0)
				{				
					newid=trial->id;
				}
							
			}
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{				
				if(strcmp(user2,trial->name)==0)
				{
					for(i=0;i<trial->followerCounter;i++)
					{
						if(trial->followers[i]==newid)
						{
							temp=trial->followers[i];
							trial->followers[i]=trial->followers[trial->followerCounter-1];							
							trial->followers[trial->followerCounter-1]=temp;
							trial->followers[trial->followerCounter-1]=NULL;
							trial->followerCounter--;
						}
					}
				}
			}
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{
				if(strcmp(user2,trial->name)==0)
				{
					array=trial->sentMessages;
					len=trial->sentMessageListCounter;
				}
			}	
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{
				if(strcmp(trial->name,user1)==0)
				{
					for(k=0;k<=len;k++)
					{
						for(j=0;j<trial->messageListCounter;j++)
						{
							if(array[k]==trial->messages[j])
							{
								trial->messages[j]=-9;
							}
						}
					}
					trial->messageListCounter--;
				}
			}
			for(trial=first->next;trial!=NULL;trial=trial->next)
			{
				if(strcmp(trial->name,user1)==0)
				{
					for(l=0;l<trial->messageListCounter;l++)
					{
						if(trial->messages[l]==-9)
						{
							counter++;
							for(n=l;n<trial->messageListCounter;n++)
							{
								temp2=trial->messages[n];
								trial->messages[n]=trial->messages[n+1];
								trial->messages[n+1]=temp2;
								trial->messages[trial->messageListCounter-counter]=NULL;
							}
						}
					}
				}
			}	
		}
	}
	struct account *trial;			
	for(trial=first;trial->next!=NULL;trial=trial->next)
	{
		fprintf(output,"%d: ",trial->next->id);
		for(i=0;i<trial->next->messageListCounter;i++)
		{
			fprintf(output,"%d ",trial->next->messages[i]);	
			
		}fprintf(output,"\n");
	}
}
