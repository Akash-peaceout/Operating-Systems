#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

void merge(int v[],int s, int e)
{
    if(e==s)    
      return; 
    //if there is just one number
    int m=(s+e)/2;
    pid_t f1,f2;
    if((f1=vfork())==0)
    {
     merge(v,s,m);
     exit(0);
    } //sort the numbers from position s to position m
    if((f2=vfork())==0) 
    {
     merge(v,m+1,e); 
     exit(0);
    } //same for numbers from position m+1 to e
    waitpid(f1,NULL,0); //wait until the first half is sorted
    waitpid(f2,NULL,0); //same for the second half
    int *t=(int*)malloc((e-s+1)*sizeof(int)); //temporary array for merging the 2 halves
    int k=0,i=s,j=m+1;
    while((i<=m)&&(j<=e)) //while there are stil unprocessed numbers left in each half
        if(v[i]<v[j])   
         t[k++]=v[i++];
        else            
          t[k++]=v[j++];
    while(i<=m)         
    {t[k++]=v[i++];}
 //copy the remaining numbers
    while(j<=e)         
    {t[k++]=v[j++];}
    while(k)            
    {v[e--]=t[--k];} //copy them back in the original array
    free(t); //delete the temporary array
}

int main() 
{
 int i,j,n,a[100],t;
 pid_t pid1,pid2;
 printf("\nEnter no. of numbers:");
 scanf("%d",&n);
 printf("\nEnter the array elements");
 for(i=0;i<n;i++)
scanf("%d",&a[i]);
    
    merge(a,0,n-1);
    printf("\nSorted array is :");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
 

return 0;
}

