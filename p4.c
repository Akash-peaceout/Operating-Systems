#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
        int     fd[2];
        pid_t   pid;
        char    string[20];
        printf("\nEnter string :");
        gets(string);
        char    readbuffer[80];

        pipe(fd);

        if((pid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(pid == 0)
        {
                close(fd[0]);  // Child process closes up input side of pipe 
                /* Send string through the output side of pipe */
                write(fd[1], string, (strlen(string)+1));
                
                exit(0);
        }
        else
        {
                close(fd[1]);    // Parent process closes up output side of pipe 
                /* Read in a string from the pipe */
                while(read(fd[0], readbuffer, sizeof(readbuffer))>0);
                { 
                  char temp[80];
                  strcpy(temp,strrev(readbuffer));
                  if(strcmp(readbuffer,temp)==0)
                   printf("\nPalindrome");
                  else
                   printf("\nNot palindrome");
                 }
              
        }

        return(0);
}
