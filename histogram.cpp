#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char a[100],b[100];
	gets(a);
	int i=0,j=0,l=0, count[100],k=0,count2[100];
	char ch;
	cout<<"\n";
	pid_t pid;        
    pid = vfork();

    if(pid==0)
    {
	for(i=0;i<100;i++)
		count[i]=0;
	for(i=0;a[i]!='\0';i++)
	{
		ch=a[i];
		
		
		for(j=0;a[j]!='\0';j++)
		{
			if(a[j]==ch)
			{
				count[i]++;
			}
			
		}

	
	}
	exit(0);
}
else
{
	wait(NULL);
 int f=strlen(a);

int co=0;
for(i=0;i<f;i++)
{
for(j=0;j<i;j++)
{
if(a[i]==b[j])
{
co=1;
}
}
if(co==0)
{
b[k]=a[i];
count2[k]=count[i];
k++;

}
co=0;
}

 
	for(i=0;b[i]!='\0';i++)
	{
			cout<<"\nCharacter "<<b[i]<<" : ";
		for(k=0;k< count2[i];k++)
		{
			
			cout<<"*";
		}

	}
}
		cout<<"\n";
    
    return 0;
}