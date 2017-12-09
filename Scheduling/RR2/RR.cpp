#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
using namespace std;

class process
{
public:
 int id,at,bt,st,ft,pr;
 float wt,tat;
};

process p[10],p1[10],temp;
queue<int> q1;

int accept(int ch);
void turnwait(int n);
void display(int n);
void scheduleRR(int n);

int main()
{
 int i,n,ts,ch,j,x;
 p[0].tat=0;
 p[0].wt=0;
 n=accept(ch);
 scheduleRR(n);
 turnwait(n);
 display(n);
 return 0;
}

int accept(int ch)
{
 int i,n;
 printf("\nEnter the no. of process: ");
 scanf("%d",&n);
 if(n==0)
 {
  printf("\nInvalid no. of process");
  exit(1);
 }
 for(i=1;i<=n;i++)
 {
  printf("\nEnter the arrival time for process P%d: ",i);
  scanf("%d",&p[i].at);
  p[i].id=i;
 }
 for(i=1;i<=n;i++)
 {
  printf("\nEnter the burst time for process P%d: ",i);
  scanf("%d",&p[i].bt);
 } 
 for(i=1;i<=n;i++)
  p1[i]=p[i];
 return n;
}

void scheduleRR(int n)
{ 
 int i,ts,m,nextval,nextarr; 
 nextval=p1[1].at;
 i=1;
 cout<<"\nEnter time slice: ";
 cin>>ts;
 for(i=1;i<=n && p1[i].at<=nextval;i++)
  q1.push(p1[i].id);

 while(!q1.empty()) 
 { 
  m=q1.front();
  q1.pop();
  if(p1[m].bt>=ts){
   nextval=nextval+ts; 
   p1[m].bt=p1[m].bt-ts;
  }
  else{
   nextval=nextval+p1[m].bt; 
   p1[m].bt=0; 
  }

   
  while(i<=n && p1[i].at<=nextval) // new
  {
   q1.push(p1[i].id);
   i++;
  }

  if(p1[m].bt>0)
   q1.push(m);
  if(p1[m].bt<=0)
   p[m].ft=nextval;
 }
}

void turnwait(int n)
{
 int i; 
 for(i=1;i<=n;i++)
 {
  p[i].tat=p[i].ft-p[i].at;
  p[i].wt=p[i].tat-p[i].bt;
  p[0].tat=p[0].tat+p[i].tat;  // average stored in index 0
  p[0].wt=p[0].wt+p[i].wt;
 }   
 p[0].tat=p[0].tat/n;
 p[0].wt=p[0].wt/n;
}

void display(int n)
{
 int i; 
 cout<<"\n\n-------------------TABLE----------------------------------\n";
 printf("\nProcess\tAT\tBT\tFT\tTAT\t\tWT");
 for(i=1;i<=n;i++)
  printf("\nP%d\t%d\t%d\t%d\t%f\t%f",p[i].id,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt);
 cout<<"\n\n-----------------------------------------------------------";
 printf("\nAverage Turn Around Time: %f",p[0].tat);
 printf("\nAverage Waiting Time: %f\n",p[0].wt);
}