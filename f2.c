#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main() 
{
 int i,n,j=1,flag=0;
 pid_t pid;
pid=vfork();

if(pid==0)
{
 printf("\nEnter no. of numbers:");
 scanf("%d",&n);
 printf("\n");
 _exit(0);
 
}
else if(pid>0)
{
 wait(NULL);
if(n==1 || n==2)
printf("\nNeither prime nor composite");
else
{
 while (j< n)
    {
        flag = 0;
        
        for(i = 2; i <= j/2; ++i)
        {
            if(j % i == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0 && j!=1 && j!=2 )
            printf("%d ", j);

        ++j;
    }
  
}
} 
else
printf("INVALID FORK");
return 0;
}

