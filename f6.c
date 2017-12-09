//Zombie. 

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
     printf("\nZOMBIE\n");
    pid_t childpid = fork();

    if (childpid > 0)
       {
        sleep(5);
       }
    else       
        {
          printf("[=,, 0_o ]=,,\n");
         exit(0);
        }
    return 0;
}
