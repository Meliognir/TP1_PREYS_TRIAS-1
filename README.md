# TP1_PREYS_TRIAS
Synthesis Practical Work Ensea in the Shell

**Question 1 :**
The answer to this question is inside the file called "enseash.c".
For this question, we learned to separate the variable used in a different file called "constantHeader.h". This allows us to not accumulate a lot of variables in the main in order to see better what we are doing. 
We used the function write that takes three arguments, firstly, STDOUT_FILENO, which allows the message to be written in the console, then the message displayed, and finally the length of the message (we use a strlen() for that).

**Question 2 :**
We will answer in order. 
**a)** Firstly, we use the function read that takes three arguments, STD
**b)** We use the command execlp, which takes in argument a buffer two times, then a NULL. The first argument will be considered the name of the file that have to be searched and the NULL is mandatory to indicate the end of the arguments. 
**c)**We don't use printf() for this question.
