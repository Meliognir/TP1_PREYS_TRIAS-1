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



int main(int argc, char *argv[]){
	char *buf=0;
	buf=calloc(BUFFERSIZE,sizeof(char)); //Dynamic allocation of memory 
	int statusOut=write(STDOUT_FILENO,WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));//Display of the welcome message of the shell with write function
	int exiting=0;
	
	char error_message[ERROR0_MESSAGE_SIZE];
	struct timespec start, end;
	double elapsed_time;
	
	char *token;
	const char * separators = " ";
	
	while(exiting!=1){
		
		int command =read(STDIN_FILENO,buf,BUFFERSIZE);
		buf[strlen(buf)-1]=0; //the last character of the buf is disappearing to be consider as a string

		//Question 3 
		buf[command-1]='\0';
		
		if (strcmp(buf, "exit") == 0 || command == 0) { // we exit thanks to exit or to crtl+D
			write(STDOUT_FILENO, EXIT_MESSAGE, strlen(EXIT_MESSAGE));
			exiting=1; //exiting TRUE
			break;
		}
		
		//Question 5 beginning
		clock_gettime(CLOCK_REALTIME, &start);// start of time
		
		pid_t currentPid=fork();
		
		//Question 4 

		if (currentPid==-1){
			perror("Error");// Error in the creation of the child
		}
		//Question 2 & 6 & 7
		if (currentPid==0){ 
			token = strtok(buf,separators);// token will be a pointer to character chain, it helps us considering spaces as something than can link commands
			char *args[32];// we limit the value of the input we can have to 31 character, we should have put 32 as a constant in the constantHeader file 
			int i=0;
			while (token != NULL && i < 31) {
				if (strcmp(token, "<") == 0) {
					token = strtok(NULL, separators);
                    			int fd = open(token, O_RDONLY); //open on read only to have the output
                    			dup2(fd, STDIN_FILENO);//used to duplicate file descriptors. It allows us to make a copy of a file descriptor and associate it with another file descriptor number. Here, the oldfile fd will be duplicated in STDIN_FILENO and be displayed
                    			close(fd);//we can close fd as the result is now in STDIN_FILENO
                		} else if (strcmp(token, ">") == 0) { //same process as before but with > 
					token = strtok(NULL, separators); 
                    			int fd = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0644);//token est le nom du fichier à ouvrir en Write&ReasOnly, O_CREAT pour le créer si il n'existe pas et O_TRUNC pour mettre le fichier à 0 Octer si il exitse déjà, enfin 0644 est un masque de permission local pour écrire et lire dans le fichier
                   			dup2(fd, STDOUT_FILENO);
                    			close(fd);
                		} else {
                    			args[i++] = token;
                		}
                	token = strtok(NULL, separators);
           		}
            	args[i] = NULL;
			execvp(buf,args); // if we want Q2 only : execlp(buf,buf,NULL);
			exit(-1);
		}	
		
		else{
			 waitpid(currentPid,NULL,0);//if it the pid of the father, we wait the execution of the child to go back to the child again
		}
		

		clock_gettime(CLOCK_REALTIME, &end);// end of time

		// Calculus of the time passed
		elapsed_time = (end.tv_nsec - start.tv_nsec)*1e-6; //we multiply by 1e-6 to put the value in ms 
		
                   
        if (statusOut==-1){//The files has not been created
			write(STDOUT_FILENO,ERROR1_MESSAGE,strlen(ERROR1_MESSAGE));
			exiting=1;
		}
		else{
			sprintf(error_message, "$ enseash [exit : 0| %2.1f ms]%%", elapsed_time); // no error : we display error 0
			write(STDOUT_FILENO,error_message,strlen(error_message));
		}
	}
	free(buf);
	return 0;
}
