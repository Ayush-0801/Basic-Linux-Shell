#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char* argv[])
{

	DIR *curdir;								
	struct dirent *file;
	char aes[100];

	curdir=opendir(getcwd(aes,100));

	if(argv[1]==NULL)
	{
		while((file = readdir(curdir)) != NULL)
		{
			if(file->d_name[0]=='.')
			{

			}
			else
			{
			    printf("%s ", file->d_name);
			}

		}
	}	
	else
	{

		if(!strcmp(argv[1],"-a"))
		{
			while((file = readdir(curdir)) != NULL)
			{
				
				
				    printf("%s ", file->d_name);
				
				        
			}
		}
		else if(!strcmp(argv[1],"-1"))
		{
			while((file = readdir(curdir)) != NULL)
			{
				if(!strcmp(file->d_name,".")||!strcmp(file->d_name,".."))
				{

				}
				else
				{
				    printf("%s \n", file->d_name);
				}
				        
			}
		}
		else
		{
			printf("Invalid Option\n");
		}

	}


	closedir(curdir);
	printf("\n");

}