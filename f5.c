#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include <stdlib.h>
int main()
{
         
    int pid = fork();
 
    if (pid ==0)
      {  
        sleep(2);
        printf("\norphan child :(");
	exit(0);
      }
    else if (pid >0)
    {

wait(NULL); 
printf("\nThe parent"); 
    }
 
    return 0;
}
