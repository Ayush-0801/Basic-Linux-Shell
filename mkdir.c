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


			if(!strcmp(opt,"-v"))
	   		{
	   			char* direc;
	   			while((direc=strtok(NULL," "))!=NULL)
	   			{
	   				mkdir(direc,0777);
	   				printf("mkdir: created directory '%s'\n",direc);
	   			}
	   			
	   			

	   		}
	   		else if (!strcmp(opt,"-p"))
	   		{
	   			int count=0;
	   			char* name=strtok(NULL," ");

	   			char* direc=strtok(name,"/");
	   			mkdir(direc,0777);
	   			chdir(direc);

	   			while(direc!=NULL)
	   			{
	   				direc=strtok(NULL,"/");
	   				mkdir(direc,0777);
	   				chdir(direc);
	   				count++;
	   			}

	   			for(int i=0;i<count;i++)
	   			{
	   				chdir("..");
	   			}
	   		
	   		}
	   		else
	   		{
	   			char* direc;
				mkdir(opt,0777);
				while((direc=strtok(NULL," "))!=NULL)
				{
					mkdir(direc,0777);
				}
	   		}

	   		return 0;

}