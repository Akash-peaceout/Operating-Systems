
#include <iostream>
#include "hrrn.h"
#include <limits.h>

using namespace std;


void hrrn::readData()
{
	cout<<"Enter no. of processes\n";
	cin>>n;
	cout<<"Enter the arrival times :\n";
	for(int i=0;i<n;i++)
	cin>>at[i];

	cout<<"Enter the corresponding burst times:\n";
	for(int i=0;i<n;i++)
	cin>>bt[i];


	
}


void hrrn::Init(){
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

void hrrn::computehrrn(){

	int time,next=0,old,i;
	cout<<"Gantt Chart\n ";
	for(time=0;time<total;)
	{
		old=next;	
		next=getNextProcess(time);

		if(next == -1) {
			if(old!=next)
		 	cout<<"["<<time<<"]|--IDLE--|";

		 	total++;
		 	time++;
		 	continue;
		}

		 cout<<"["<<time<<"]|--P"<<next+1<<"--|";
		finish[next]=1;
		time = time + bt[next];
		
		// computing wait time 
		for(i=0;i<n;i++)
			if(i!=next && finish[i]==0 && at[i]<=time)
				wt[i]++;

	}
	cout<<"["<<total<<"]"<<endl;


	dispTime();

}

int hrrn::getNextProcess(int time){

		int i , index = 0;
		float maxRR = 0.0;
		bool flag = false;
		

		for(i=0;i<n;i++)
			if(finish[i]!=1)
				if(at[i]<=time)
				{
						float rr = ((float)(time - at[i] + bt[i]))/(float)bt[i];

						if(rr > maxRR)
						{
							maxRR = rr;
							index=i;
							flag = true;
						}
						
				}
		
		if(flag == false)
			return -1;

		return index;

}

void hrrn::dispTime()
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