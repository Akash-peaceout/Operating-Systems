#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main() 
{
 int i,j,n,a[100],t;
 pid_t pid;
 printf("\nEnter no. of numbers:");
 scanf("%d",&n);
 printf("\nEnter the array elements");
 for(i=0;i<n;i++)
scanf("%d",&a[i]);
 
pid=fork();

if(pid==0)
{
 for(i=0;i<n-1;i++)
 for(j=0;j<n-1-i;j++)
  if(a[j]<a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
printf("\nDescending:");
for(i=0;i<n;i++)
printf("%d ",a[i]);
 printf("\n");
 _exit(0);
 
}
else if(pid>0)
{
 wait(NULL);
 for(i=0;i<n-1;i++)
 for(j=0;j<n-1-i;j++)
  if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
printf("\nAscending:");
for(i=0;i<n;i++)
printf("%d ",a[i]);
 
} 
else
printf("INVALID FORK");
return 0;
}

