#include "fcfs.h"
#include <iostream>
#include <limits.h>

using namespace std;

fcfs :: fcfs(int numOfProcess)
{
	this->numOfProcesses = numOfProcess;
	bt = new int[numOfProcess];
	wt = new int[numOfProcess];
	tat = new int[numOfProcess];
    at = new int[numOfProcess];
    selectedOrder = new int[numOfProcess];
	avwt = avtat = 0;

    for(int i =0 ;i < numOfProcesses ; i++)
        selectedOrder[i] = -1;
}

void fcfs :: setBurstTime(int pid , int burstTime)
{
	bt[pid] = burstTime;
}

void fcfs :: setArrivalTime(int pid , int arrvTime)
{
    at[pid] = arrvTime;
}
	
void fcfs :: scheduleFCFS()
{
    int counter = 1;
    for(int j=0; j< numOfProcesses ; j++)
    {
        int minArrv = INT_MAX;
        int index = 0;

        for(int i =0 ; i < numOfProcesses ;i++)
        {
            if(selectedOrder[i] == -1)
                if(at[i] < minArrv || (at[i] == minArrv && bt[i] <= bt[index]))
                {
                    minArrv = at[i];
                    index =i;
                }
        }
        selectedOrder[index] =counter++;
    }
}

void fcfs::calculateWaitingTime()
{
	int total =0,i,j;
 
    //calculate waiting time
    for(i=1;i<=numOfProcesses;i++)
    {
        int j = getPIDfromSchedule(i);
        int k = getPIDfromSchedule(i-1);

		if(k == -1)
			wt[j] = 0;
		else
		wt[j]= (at[k] + bt[k] +wt[k]) - at[j];       
      
 
        total+=wt[j];
    }
 
    avwt=(float)total/numOfProcesses; 
}

int fcfs :: getPIDfromSchedule(int a)
{
	for(int i =0 ;i <numOfProcesses ;i++)
		if(selectedOrder[i] == a)
			return i;

		return -1;
}

void fcfs::showProcesses()
{
	 cout<<"\nProcess\t\tArrivalTime\tBurst Time\tWaiting Time\tTurnaround Time\t Schedule Order";
 
	for(int i=0;i<numOfProcesses;i++)
    {
       
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<selectedOrder[i];
    }

    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;

}

void fcfs :: calculateTurnAroundTime()
{
	int i;
    avtat = 0;
    for(i=0;i<numOfProcesses;i++)
    {
        tat[i]=bt[i]+wt[i];
        avtat+=tat[i];
        
    }
    avtat= avtat / (float) numOfProcesses;
}
