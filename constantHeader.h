#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//Constant for Q1 & Q2
#define WELCOME_MESSAGE "$ ./enseash \nWelcome to ENSEA Tiny Shell. \nPour quitter, tapez 'exit'. \nenseash %\n"

//Constant for Q2
#define BUFFERSIZE 128

//Constant Q3
#define EXIT_MESSAGE "enseash % exit\nBye bye...\n$\n"


