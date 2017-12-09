#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include<ctype.h>

int main(void)
{
        int     fd[2],wc=1,cc=0,lc=1,sc=1;
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
                while(read(fd[0], readbuffer, sizeof(readbuffer))>0)
                { 
                  int i;
                  for(i=0;i<strlen(readbuffer);i++)
                   {
                     cc++;
                     if(readbuffer[i]=='\n')
                        lc++;
                     if(readbuffer[i]==' ')
                         wc++;
                     if(readbuffer[i]=='.')
                         sc++;
                   }
                }
                printf("\nWord count:%d\nChar count:%d\nLine count:%d\nSentance count:%d\n",wc,cc,lc,sc);
        }

        return(0);
}
