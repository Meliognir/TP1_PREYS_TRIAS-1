
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#include "constantHeader.h"



int main(){
	 
	write(STDOUT_FILENO,WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));
    return 0;

}
 

