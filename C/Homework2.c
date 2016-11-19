#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*********************  SCAN INPUT-DELETE SPACES-DELETE DOUBLE -'S ****************/
char *orderingInput()
{	
	char* input=malloc(1);
	int i=0,j,counter=0;
	while((input[i]=getchar())!=EOF)
	{
		if(!isspace(input[i]) && input[i]!="\n")
		{
			if(input[i]!="\n")			
			{
				i++;			
				input=realloc(input,i+1);		
			}
		}		
	}
	input[i]=NULL;
	for(j=0;j<i;j++)
	{		
		input[j-counter]=input[j];		
		if(input[j-1]=='-')
		{
			if(input[j]=='-') {counter=counter+2;}
		}
	}
	input[j-counter]=NULL;
	return input;
}


char *deleteNegatives(char *input)
{
	int i,j,len;
	len=strlen(input);
	for(i=0;i<len;i++)
	{
		if(input[i]=='-' && (input[i+1]=='F' || input[i+1]=='T'))
		{
			if(input[i+1]=='F')
			{
				input[i]='T';
				for(j=i;j<len;j++)
				{
					input[j+1]=input[j+2];
				}
			}  		
			if(input[i+1]=='T')			
			{			
				input[i]='F';
				j=i;			
				for(j=i;j<len;j++)
				{
					input[j+1]=input[j+2];
				}
			}
		}
		
	}
	return input;
}


/*************************** OPERATORS **********************************/

char conjunction(char n, char n2)
{
	char result;	
	if(n=='T' && n2=='T')
	{
		result='T';
	}
	if(n=='T' && n2=='F')
	{
		result='F';
	}
	if(n=='F' && n2=='T')
	{
		result='F';
	}
	if(n=='F' && n2=='F')
	{
		result='F';
	}
	return result;
}

char disjunction(char n, char n2)
{
	char result;	
	if(n=='T' && n2=='T')
	{
		result='T';
	}
	if(n=='T' && n2=='F')
	{
		result='T';
	}
	if(n=='F' && n2=='T')
	{
		result='T';
	}
	if(n=='F' && n2=='F')
	{
		result='F';
	}
	return result;
}

char implication(char n, char n2)
{
	char result;	
	if(n=='T' && n2=='T')
	{
		result='T';
	}
	if(n=='T' && n2=='F')
	{
		result='F';
	}
	if(n=='F' && n2=='T')
	{
		result='T';
	}
	if(n=='F' && n2=='F')
	{
		result='T';
	}
	return result;
}

char equivalence(char n, char n2)
{
	char result;	
	if(n=='T' && n2=='T')
	{
		result='T';
	}
	if(n=='T' && n2=='F')
	{
		result='F';
	}
	if(n=='F' && n2=='T')
	{
		result='F';
	}
	if(n=='F' && n2=='F')
	{
		result='T';
	}
	return result;
}

/*************************** EVALUATE-RECURSION **********************************/

char *checkOperators(char *input)
{	
	int i,j,len;
	deleteNegatives(input);	
	len=strlen(input);
	if(len==1)
		{
			return input;
		}
	else
	{			
		for(i=0;i<len;i++)
		{
			if((input[i]=='&') && (input[i+1]=='T' || input[i+1]=='F') && (input[i-1]=='T' || input[i-1]=='F'))
			{
				if(input[i+2]==')')
				{
					input[i-2]=conjunction(input[i-1],input[i+1]);
					for(j=i+2;j<len;j++)
					{
						input[j-3]=input[j+1];	
					}
				}
				break;
			}
			if((input[i]=='|') && (input[i+1]=='T' || input[i+1]=='F') && (input[i-1]=='T' || input[i-1]=='F'))
			{
				if(input[i+2]==')')
				{
					input[i-2]=disjunction(input[i-1],input[i+1]);
					for(j=i+2;j<len;j++)
					{
						input[j-3]=input[j+1];	
					}
				}
				break;
			}
			if((input[i]=='>') && (input[i+1]=='T' || input[i+1]=='F') && (input[i-1]=='T' || input[i-1]=='F'))
			{
				if(input[i+2]==')')
				{
					input[i-2]=implication(input[i-1],input[i+1]);
					for(j=i+2;j<len;j++)
					{
						input[j-3]=input[j+1];	
					}
				}
				break;
			}
			if((input[i]=='=') && (input[i+1]=='T' || input[i+1]=='F') && (input[i-1]=='T' || input[i-1]=='F'))
			{
				if(input[i+2]==')')
				{
					input[i-2]=equivalence(input[i-1],input[i+1]);
					for(j=i+2;j<len;j++)
					{
						input[j-3]=input[j+1];	
					}
				}
				break;
			}	
		}	
	}
	checkOperators(input);
	deleteNegatives(input);
	return input;
}

/*****************************GETTING LETTERS****************************************/

char *gettingLetters(char *input)
{
	int i,j=0,len,counter=0;
	char *result=malloc(counter*sizeof(char));
	len=strlen(input);
	for(i=0;i<len;i++)
	{
		if(islower(input[i]))
		{
			counter++;
			while(j<counter)
			{
				result[j]=input[i];
				j++;
			}
		}
	}
	return result;
}

/*****************************ORDERING LETTERS*******************************/

char *orderingLetters(char *input)
{
	int i,j=0,k,m=0,p,r,s,u,t,l=0,len,len2,len3,len4,len5;
	char *pointer,*result=malloc(len+1),n,*result2=malloc(len2+len2-1),*result3=malloc(len5+2);
	len=strlen(input);
	pointer=input;
	for(n='a';n<='z';n++)
	{
		for(i=0;i<len;i++)
		{
			if(input[i]==n)
			{
				result[j]=input[i];
				j++;
			}
			pointer++;
		}
		pointer=input;
	}
	result[j]=NULL;
	len2=strlen(result);
	len3=len2/sizeof(result[0]);
	for(r=0;r<len3;r++)
	{
		for(s=r+1;s<len3;s++)
		{
			if(result[r]==result[s])
			{
				for(u=s;u<len3;u++)
					result[u]=result[u+1];
				len3--;			
			}
			else
				s++;
		}
	}
	result[len3]=NULL;
	return result;
}

int power(int number)
{
	int i=0,j=1;
	while(i < number)
	{
		j=j*2;
		i++;
	}
	return j;
}

int main()
{
	char *result;
	char letters[30];
	char* result2;
	int* counter;
	int harfs,i,j,k,remain,len,o;
	char* counter2;
	result=orderingInput();
	len=strlen(result);
	strcpy(letters,orderingLetters(result));
	result2=malloc(sizeof(char)*len);
	harfs=strlen(letters);
	counter=malloc(sizeof(int)*harfs);
	counter2=malloc(sizeof(char)*harfs);
	i=0;
	k=power(harfs);
	for(j=0;j<harfs;j++)
	{
	printf("%c ",letters[j]);
	}
	printf("R\n");
	for(j=0;j<harfs;j++)
	{
		counter[j]=0;
		counter2[j]='+';
	}
	for(i=0; i<k; i++)
	{	
		strcpy(result2,result);
		j=0;
		for(j=0;j<harfs;j++)
		{
			remain=power(harfs-(j+1));
			if(counter[j]<remain && counter2[j]=='+')
			{
				printf("T ");
				counter[j]=(counter[j]+1);
				if(counter[j]==remain)
				{
					counter2[j]='-';		
				}
				for(o=0;o<len;o++)
				{
					if(result2[o]==letters[j] && islower(result2[o]))
					{	
						result2[o]='T';
					}
				}
				

			}
			else
			{
				printf("F ");
				counter[j]=(counter[j]-1);
				if(counter[j]==0)
				{
					counter2[j]='+';
				}
				for(o=0;o<len;o++)
				{
					if(result2[o]==letters[j] && islower(result2[o]))
					{
						result2[o]='F';
					}
				}
				
			}
		}		
		printf("%s",checkOperators(result2));
		printf("\n");
	}
}
