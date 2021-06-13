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

	if(!strcmp(opt,"-n"))
	   		{

	   			char* fle;
	   			int count=0;
	   			while((fle=strtok(NULL," "))!=NULL)
	   			{
	   				char path[100];
		   			FILE *run=fopen(strcat(strcat(getcwd(path,100),"/"),fle ),"r");

		   			if(run==NULL)
		   			{
		   				printf("File not found\n");
		   			}

					char line[100];
					int i=0;
		   			while(fgets(line,sizeof(line),run))
		   			{
		   				printf("	%d %s",count+1,line);
		   				count++;
		   				i++;
		   			}
	   			}
	   			

	   		}
	   		else if(!strcmp(opt,"-s"))
	   		{
	   			char path[100];
	   			char* fle;
	   			while((fle=strtok(NULL," "))!=NULL)
	   			{
		   			FILE *run=fopen(strcat(strcat(getcwd(path,100),"/") ,fle),"r");

		   			if(run==NULL)
		   			{
		   				printf("File not found\n");
		   			}

		   			char line[100];
		   			while(fgets(line,sizeof(line),run))
		   			{
		   				printf("%s",line);
		   				if(!strcmp(line,"\n"))
		   				{
		   					while(fgets(line,sizeof(line),run))
		   					{
		   						if(!strcmp(line,"\n"))
		   						{

		   						}
		   						else
		   						{
		   							printf("%s",line);
		   							break;
		   						}
		   					}
		   				}
		   				
		   			}
		   		}	

	   		}
	   		else 
	   		{
	   			char path[100];
	   			FILE *run=fopen(strcat(strcat(getcwd(path,100),"/"),opt),"r");

	   			if(run==NULL)
		   		{
		   			printf("File not found\n");
		   		}

	   			char line[100];
	   			while(fgets(line,sizeof(line),run))
	   			{
	   				printf("%s",line);
	   			}

	   			char* fle;
	   			while((fle=strtok(NULL," "))!=NULL)
	   			{

	   				FILE *run=fopen(strcat(strcat(getcwd(path,100),"/"),fle),"r");

		   			char line[100];
		   			while(fgets(line,sizeof(line),run))
		   			{
		   				printf("%s",line);
		   			}

	   			}


	   		}

	   		return 0;
}