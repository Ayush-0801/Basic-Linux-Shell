#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<dirent.h>
#include <sys/stat.h>
#include<time.h>

int main(int argc, char* argv[])
{

	strtok(argv[1]," ");
	char* opt=strtok(NULL," ");

	if(!strcmp(opt,"-i"))
	{
	   	char* del;

	   	while((del=strtok(NULL," "))!=NULL)
	   	{
	   		char c='n';
		   	printf("rm: Are you sure you want to delete this file'%s'?",del);
		   	scanf("%[^\n]%*c",&c);
		   	if(c=='y')
		   	{
		   		FILE *isfile;
			   	if(isfile=fopen(del,"r"))
			   	{
			   		remove(del);
			   	}
			   	else
			   		{
			   			printf("File not found\n");
			   		}
			  				
		   		}
		   	
	   		}

	   			
	  	}
	   	else if(!strcmp(opt,"-d"))
   		{
	   		char* del;
	   		while((del=strtok(NULL," "))!=NULL)
	   		{
	   			int n=rmdir(del);

	   			if(n==-1)
	   			{
	   				printf("Directory not empty\n");
	   			}

	   		}
	   			
	   	}

	   	else
	   	{
	  		char* del;
	   		FILE *isfile;
	   		if(isfile=fopen(opt,"r"))
	   		{
	   			remove(opt);
	   		}
	   		else
	   		{
	   			printf("File not found\n");
	   		}

	   		while((del=strtok(NULL," "))!=NULL)
			{
				FILE *isfile;
		  		if(isfile=fopen(del,"r"))
		   		{
		   			remove(del);
		   		}
		   		else
		   		{
		   		printf("File not found\n");
		   		}
			}

	   	
	   	}
}