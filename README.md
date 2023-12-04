## TP1_PREYS_TRIAS
Synthesis Practical Work Ensea in the Shell

#**Question 1 :**    
The answer to this question is inside the file called "enseash.c".  
For this question, we learned to separate the variable used in a different file called "constantHeader.h". This allows us to not accumulate a lot of variables in the main in order to see better what we are doing.   
We used the function write that takes three arguments, firstly, STDOUT_FILENO, which allows the message to be written in the console, then the message displayed, and finally the length of the message (we use a strlen() for that).  
**Difficulties :** We encounter almost no difficulties on that question.  

#**From this question until the end, all the answers can be found in the file "enseashell.c"**  

#**Question 2 :**  
We will answer in order. <br />
**a)** We relearned how to well use the read function.   
**b)** We learned the use of execlp, which takes in argument a buffer two times, then a NULL. The first argument will be considered the name of the file that have to be searched and the NULL is mandatory to indicate the end of the arguments.   
**c)** Nothing particuliar except we have to manage well when we go out of the loop we created.
**Difficulties :** For this question, we've met some difficulties for example, to read the file, the execlp was hard to understand at first too.  

#**Question 3 :**  
We had some difficulties doing this part : first because we forgot to erase the last character of the buffer and we need the \n to be the right character for exit, then as we are doing a loop on exiting we forgot to change the value to 1 when we needed to. But in the end it is working just fine.  

#**Question 4 :**  
We did this question the easy way, so we didn't really learned or had difficulties for this question except we used write again.  

#**Question 5 :**  
We had to learn how to use clock_gettime : it's taking 2 arguments, it retrieve and set the time for a specific clock, in our case CLOCK_REALTIME, and the secnod variable is a pointer to a specific time. We also learned the use of tv_nsec to put a time in nanoseconde.  

#**Question 6 :**  
We had a lot of difficulties with this one :  
**1/** the use of execvp insteas of execlp, execvp is taking 2 arguments : qui prend un char * en premier argument et un *char en second. The file in first(our buffer) and then the second is token we used which is 2/ :  
**2/** the use of the strtok function which breaks a string into a sequence of zero or more noempty tokens, the second arguments is the specifies the set of bytes that delimit the token  
**3/** for some reason we also had a problem with the timer implementing this... we managed to solve it by changing /1e-6 by *1e-6 which is a bit a mystery...  

#**Question 7 :**  
This part was nor difficult nor hard, it took us some time but the idea that we had worked near the first try... We relearned the use of open() and is arguments. We only had trouble with the dup2() because we didn't thought of using it at first but it allows us to save the data of our file more easily.
