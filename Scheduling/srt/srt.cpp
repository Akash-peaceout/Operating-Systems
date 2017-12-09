
#include <iostream>
#include "srt.h"
#include <limits.h>

using namespace std;


void srt::readData()
{
    cout<<"\nSRT";
	cout<<"\nEnter no. of processes:";
	cin>>n;
	cout<<"\nEnter the arrival times :";
	for(int i=0;i<n;i++)
	cin>>at[i];

	cout<<"\nEnter the corresponding burst times:";
	for(int i=0;i<n;i++)
	cin>>bt[i];

}










void srt::Init(){
	total=0;
	twt=0;
	ttat=0;
	for(int i=0; i<n; i++)
{
		rt[i]=bt[i];
		finish[i]=0;
		wt[i]=0;
		tat[i]=0;
		total+=bt[i];
		}
}

void srt::computeSRT(){

	int time,next=0,old,i;
	cout<<"Gantt Chart\n ";
	for(time=0;time<total;time++)
	{
		old=next;
		next=getNextProcess(time);

		if(next == -1) {
			if(old!=next)
		 	cout<<"("<<time<<")|_____|";

		 	total++;
		 	continue;
		}

		if(old!=next || time==0) cout<<"("<<time<<")  P"<<next+1<<"    ";
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

int srt::getNextProcess(int time){

		int i,minRemaining = INT_MAX , index = 0;

		for(i=0;i<n;i++)
			if(finish[i]!=1)
				if(rt[i]<minRemaining && at[i]<=time)
				{
						minRemaining = rt[i];
						index=i;
				}

		if(minRemaining == INT_MAX)
			return -1;

		return index;

}

void srt::dispTime()
{
	for(int i=0;i<n;i++)
	{

		twt+=wt[i];
		tat[i]=wt[i]+bt[i];
		ttat+=tat[i];
		cout<<" P"<<(i+1)<<" :   W T = "<<wt[i];
		cout<<"\n \tT A T = "<<tat[i]<<endl;

	}

	cout<<"Avg Waiting time = "<<(double)twt/n<<" and Avg Turnaround time = "<<(double)ttat/n<<endl;
	cout<<"\n";
}
