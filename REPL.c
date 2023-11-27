#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>


#include "constantHeader.h"



int main(){
	char *buf=0;
	int exiting =1;
	buf=calloc(BUFFERSIZE,sizeof(char)); //Dynamic allocation of memory 
	
	while(exiting!=0){
	
		int statusOut =write(STDOUT_FILENO,WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));
		read(STDIN_FILENO,buf,BUFFERSIZE);
		if (statusOut==-1){
			perror("Writing error");//The files has not been created
			exiting=0;
		}
		
		if (strcmp(buf,"exit\n")==0){
			write(STDOUT_FILENO,EXIT_MESSAGE, strlen(EXIT_MESSAGE));
			return 0;
		}
		
		pid_t currentPid=fork();
		
		if (currentPid==-1){
			perror("Error");// Error in the creation of the child
		}
		if (currentPid==0){
			buf[strlen(buf)-1]=0; //the last character of the buf is disappearing to read exactly what we want and no more
			execlp(buf,buf,NULL);
		}
		
			
		else{
			int status;
			waitpid(currentPid,&status,0);//if it the pid of the father, we wait hte execution of the child to go back to the child again
		}
		
		
	}
	return 0;
}
