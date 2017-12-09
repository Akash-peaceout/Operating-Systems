
#include <iostream>
#include "staticPriority.h"
#include <limits.h>

using namespace std;


void StaticPriority::readData()
{
	cout<<"Enter no. of processes\n";
	cin>>n;
	cout<<"Enter the arrival times :\n";
	for(int i=0;i<n;i++)
	cin>>at[i];

	cout<<"Enter the corresponding burst times:\n";
	for(int i=0;i<n;i++)
	cin>>bt[i];

	cout<<"Enter the corresponding Priorities:\n";
	for(int i=0;i<n;i++)
	cin>>priority[i];
	
}


void StaticPriority::Init(){
	total=0;
	twt=0;
	ttat=0;
	for(int i=0; i<n; i++){
		rt[i]=bt[i];
		finish[i]=0;
		wt[i]=0;
		tat[i]=0;
		total+=bt[i];
		}
}

void StaticPriority::computeStaticPriority(){

	int time,next=0,old,i;
	cout<<"Gantt Chart\n ";
	for(time=0;time<total;time++)
	{
		old=next;	
		next=getNextProcess(time);

		if(next == -1) {
			if(old!=next)
		 	cout<<"["<<time<<"]|--IDLE--|";

		 	total++;
		 	continue;
		}

		if(old!=next || time==0) cout<<"["<<time<<"]|--P"<<next+1<<"--|";
		rt[next]=rt[next]-1;
		if(rt[next]==0) finish[next]=1;
		
		// computing wait time 
		for(i=0;i<n;i++)
			if(i!=next && finish[i]==0 && at[i]<=time)
				wt[i]++;

	}
	cout<<"["<<total<<"]"<<endl;


	dispTime();

}

int StaticPriority::getNextProcess(int time){

		int i,maxPriority = INT_MIN , index = 0;
		
		for(i=0;i<n;i++)
			if(finish[i]!=1)
				if(priority[i]>maxPriority && at[i]<=time)
				{
						maxPriority = priority[i];
						index=i;
				}
		
		if(maxPriority == INT_MIN)
			return -1;

		return index;

}

void StaticPriority::dispTime()
{
	for(int i=0;i<n;i++)
	{

		twt+=wt[i];
		tat[i]=wt[i]+bt[i];
		ttat+=tat[i];
		cout<<" P"<<(i+1)<<" : Waiting time = "<<wt[i]<<", Turnaround time = "<<tat[i]<<endl;

	}

	cout<<"Avg Waiting time = "<<(double)twt/n<<" and Avg Turnaround time = "<<(double)ttat/n<<endl;
	cout<<"\n";
}