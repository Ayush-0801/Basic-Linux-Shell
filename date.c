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
			
	   		if(argv[1]==NULL)
	   		{
	   			struct tm *local_time;
	   			time_t curr;
	   			curr=time(NULL);
	   			local_time=localtime(&curr);
	   			printf("%s",asctime(local_time));

	   		}

	   		else
	   		{
	   			if(!strcmp(argv[1],"-u"))
		   		{
		   			struct tm *g_time;
		   			time_t now;
		   			time(&now);
		   			g_time=gmtime(&now);	
		   			printf("%s",asctime(g_time));


		   		}
		   		else if(!strcmp(argv[1],"+%d"))
		   		{
		   			struct tm *local_time;
		   			time_t curr;
		   			curr=time(NULL);
		   			local_time=localtime(&curr);
		   			printf("%d",local_time->tm_mday);
		   			printf("\n");
		   		}
		   		else
		   		{
		   			printf("Invalid Option\n");
		   		}
	   		}
	   		return 0;
}