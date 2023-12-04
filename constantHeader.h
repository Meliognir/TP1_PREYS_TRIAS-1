#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//Constant for Q1 
#define WELCOME_MESSAGE "$ ./enseash \nWelcome to ENSEA Tiny Shell. \nPour quitter, tapez 'exit'. \nenseash %\n"

//Constant for Q2
#define BUFFERSIZE 128

//Constant Q3
#define EXIT_MESSAGE "Bye bye...\n$\n"

//Constant Q4
#define ERROR0_MESSAGE "$ enseash [error : 0| %f ms]%" //when there are no errors
#define ERROR1_MESSAGE "$ enseash [error : 1]%" // when there are errors

//Constant Q5
#define ERROR0_MESSAGE_SIZE 50 // Taille de la chaîne ERROR0_MESSAGE





