
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#include "constantHeader.h"



int main(){
	int status =write(STDOUT_FILENO,WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));//strlen() gives the size of the message
	if (status==-1){
		perror("Writing error");//The files has not been created
	}
    return 0;

}
 

