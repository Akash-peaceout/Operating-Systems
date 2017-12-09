#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main() 
{
 int i,n;
 pid_t pid;
printf("\nENTER N=");
scanf("%d",&n);

pid=fork();

if(pid==0)
{
 for(i=0;i<=n;i+=2)
  printf("%d",i);
 printf("\n");
 
}
else if(pid>0)
{wait(NULL);
 for(i=1;i<=n;i+=2)
  printf("%d",i);
  
} 
else
printf("INVALID FORK");
return 0;
}

