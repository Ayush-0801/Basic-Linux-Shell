#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<dirent.h>
#include <sys/stat.h>
#include<time.h>

int main()
{
	printf("Basic Linux Shell in C \n");
	printf("INTERNAL COMMANDS: cd (.. ~) , echo (-n -e) , history (-c [number]) , pwd (-L -P) , exit \n");
	printf("EXTERNAL COMMANDS: ls(-a -1) , cat(-n -s) , date(-u [format specific]) , rm(-i -d) , mkdir(-v -p) \n");

	int status=1;
	char history[1000][100];
	int iteration=-1;
	int i=-1;

	while(status!=0)
	{
		iteration++;

		char cmd[100] ,copy1[100], copy2[100], copy3[100]; 
		char forecho[100];
		char aes[100];

		printf("\033[1;34m~%s\033[0m$ ",getcwd(aes,100));
   		scanf("%[^\n]%*c",cmd);

   		int j=0;
   		memset(copy1,0,sizeof(copy1));
   		memset(copy2,0,sizeof(copy2));
   		memset(copy3,0,sizeof(copy3));
   		while(cmd[j]!='\0')
   		{
   			copy1[j]=cmd[j];
   			copy2[j]=cmd[j];
   			copy3[j]=cmd[j];
   			j++;
   		}

   		if(strlen(cmd)!=0)
   		{
   			strcpy(history[iteration],cmd);
   		}

   		strcpy(forecho,cmd);
   		
	 	char *input;
		input=strtok(cmd," ");

	   	if(!strcmp(input,"cd"))
	   	{
	   		int n;
	   		char *dir1=strtok(NULL," ");
	   		if(!strcmp(dir1,"~"))
	   		{
	   			n=chdir("/home");
	   			if(n==-1)
	   			{
	   				printf("No such file or directory\n");
	   			}
	   		}
	   		else if(!strcmp(dir1,".."))
	   		{
	   			n=chdir("..");
	   			if(n==-1)
	   			{
	   				printf("No such file or directory\n");
	   			}
	   		}
	   		else
	   		{
	   			n=chdir(dir1);
	   			if(n==-1)
	   			{
	   				printf("No such file or directory\n");
	   			}
	   		}
	   		
	   		
	   	}

		else if(!strcmp(input,"pwd"))
	   	{
	   		char cdir[100];

	   		char* opt;
	   		opt=strtok(NULL," ");

	   		if(opt==NULL)
	   		{
	   			printf("%s \n",getcwd(cdir,100));
	   		}
	   		else
	   		{
		   		if(!strcmp(opt,"-L"))
		   		{
		   			printf("%s \n",getcwd(cdir,100));
		   		}
		   		else if(!strcmp(opt,"-P"))
		   		{
		   			printf("%s \n",getcwd(cdir,100));
		   		}
		   		else
		   		{
		   			printf("Invalid Option\n");
		   		}
	   		}

	   		
	   		
	   	}

	   	else if(!strcmp(input,"history"))
	   	{
	   		char* opt;
	   		opt=strtok(NULL," ");

	   		if(opt==NULL)
	   		{
	   			int i=0;
	   			while(strlen(history[i])!=0)
	   			{
	   				printf("%d %s\n",i+1,history[i]);
	   				i++;
	   			}

	   		}

	   		else
	   		{

		   		if(atoi(opt)!=0)
		   		{
		   			int i=iteration-atoi(opt)+1;
		   			while(strlen(history[i])!=0)
		   			{
		   				printf("%d %s\n",i+1,history[i]);
		   				i++;
		   			}

		   		}
		   		else if(!strcmp(opt,"-c"))
		   		{
		   			memset(history,0,sizeof(history));

		   			iteration=-1;


		   		}
		   		else
		   		{
		   			printf("Invalid Option\n");
		   		}
	   		}
	   		

	   	
	   	}

	   	else if(!strcmp(cmd,"exit"))
	   	{
	   		exit(0);
	   	}

	    else if(!strcmp(input,"echo"))
	   	{
	   		int flag=0 ,check=0;
	   		int i=0;
	   		char *opt=strtok(NULL," ");

	   		if(!strcmp(opt,"-n"))
	   		{
	   			while(forecho[i]!='\0')
				{

					if(forecho[i]=='n' && flag==0)
					{
						flag=1;
					}

					else if(flag==1)
					{
						if(forecho[i]==' ' && check==0)
						{
						}
						else
						{
							check=1;;						
							if(forecho[i]=='"')
							{
							}
							else
							{
								printf("%c",forecho[i]);

							}

									
						}
							

					}
					

					i++;
				}
	   		}

	   		else if(!strcmp(opt,"-e"))
	   		{
	   			while(forecho[i]!='\0')
				{

					if(forecho[i]=='-' && flag==0)
					{
						flag=1;
						i++;
					}

					else if(flag==1)
					{
						if(forecho[i]==' ' && check==0)
						{
						}
						else
						{
							check=1;;						
							if(forecho[i]=='"')
							{
							}
							else if(forecho[i]=='\\')
							{
								if(forecho[i+1]=='t')
								{
									printf("	");
								}
								else if(forecho[i+1]=='n')
								{
									printf("\n");
								}
								else if(forecho[i+1]=='c')
								{
									break;
								}
								i++;
								
							}
							else
							{
								printf("%c",forecho[i]);

							}	
						}

					}
					

					i++;
				}
				printf("\n");

	   		}

	   		else
	   		{
	   			while(forecho[i]!='\0')
				{
					if(forecho[i]=='o' && flag==0)
					{
						flag=1;
					}

					else if(flag==1)
					{
						if(forecho[i]==' ' && check==0)
						{
						}
						else
						{
							check=1;;						
							if(forecho[i]!='"')
							{
									
								printf("%c",forecho[i]);
							}
									
						}

					}

					i++;
				}
				printf("\n");
	   		}
	   		
	   			
	   		

	   	}

	   	else if(!strcmp(input,"ls"))
	   	{

	   		char* opt;
	   		opt=strtok(NULL," ");
			
	   		pid_t cp=fork();
	   		
	   		if(cp<0)
	   		{
	   			printf("Fork Failed\n");
	   		}

	   		if(cp==0)
	   		{
	   			char *args[]={"/home/ayush0801/Desktop/Assignment1/Exercise1.2/ls",opt,NULL}; 
        		execvp(args[0],args); 
        		exit(0);
	   		}
	   		else
	   		{
	   			int status;
	   			waitpid(cp,&status,0);
	   		}
	   	}

	   	else if(!strcmp(input,"mkdir"))
	   	{
	   		
			pid_t cp=fork();

			if(cp<0)
			{
				printf("Fork Failed\n");
			}
	   		

	   		if(cp==0)
	   		{
	   			char *args[]={"/home/ayush0801/Desktop/Assignment1/Exercise1.2/mkdir",copy1,NULL}; 
        		execvp(args[0],args); 
        		exit(0);
	   		}
	   		else
	   		{
	   			int status;
	   			waitpid(cp,&status,0);
	   		}

	   		

	   	}

	   	else if(!strcmp(input,"rm"))
	   	{
			pid_t cp=fork();

			if(cp<0)
			{
				printf("Fork Failed\n");
			}

	   		if(cp==0)
	   		{
	   			char *args[]={"/home/ayush0801/Desktop/Assignment1/Exercise1.2/rm",copy2,NULL}; 
        		execvp(args[0],args);
        		exit(0); 
	   		}
	   		else
	   		{
	   			int status;
	   			waitpid(cp,&status,0);
	   		}
	   		


	   	} 

	   	else if(!strcmp(input,"cat"))
	   	{
	   		char* opt;
	   		opt=strtok(NULL," ");

	   		pid_t cp=fork();

	   		if(cp<0)
			{
				printf("Fork Failed\n");
			}

	   		if(cp==0)
	   		{
	   			char *args[]={"/home/ayush0801/Desktop/Assignment1/Exercise1.2/cat",copy3,NULL}; 
        		execvp(args[0],args);
        		exit(0); 
	   		}
	   		else
	   		{
	   			int status;
	   			waitpid(cp,&status,0);
	   		}

	   	}
	   	else if(!strcmp(input,"date"))
	   	{

	   		char* opt;
	   		opt=strtok(NULL," ");


	   		pid_t cp=fork();

	   		if(cp<0)
			{
				printf("Fork Failed\n");
			}

	   		if(cp==0)
	   		{
	   			char *args[]={"/home/ayush0801/Desktop/Assignment1/Exercise1.2/date",opt,NULL}; 
        		execvp(args[0],args);
        		exit(0); 
	   		}
	   		else
	   		{
	   			int status;
	   			waitpid(cp,&status,0);
	   		}
	   	}
	   	else
	   	{
	   		printf("Invalid Command\n");
	   	}


	}

}
