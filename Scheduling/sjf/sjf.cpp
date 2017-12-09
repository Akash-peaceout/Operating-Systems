#include "sjf.h"
#include <iostream>
#include <limits.h>

using namespace std;

sjf :: sjf(int numOfProcess)
{
	this->numOfProcesses = numOfProcess;
    at = new int[numOfProcess];
	bt = new int[numOfProcess];
	wt = new int[numOfProcess];
	tat = new int[numOfProcess];
    p = new int[numOfProcess];
    selectedOrder = new int[numOfProcess];
	avwt = avtat = 0;

    for(int i =0; i<numOfProcesses; i++)
    {
       selectedOrder[i] = -1;  // no process is selected intially
       p[i] = i;

    }
}

void sjf :: setBurstTime(int pid , int burstTime)
{
	bt[pid] = burstTime;
}

void sjf :: setArrivalTime(int pid , int arrvTime)
{
    at[pid] = arrvTime;
}


void sjf :: scheduleSJF()
{
    int counter = 1 , limit =0,index =0 , minBurst;

    for(int j =0; j< numOfProcesses;j++)
    {
        minBurst = INT_MAX;

        for(int i =0; i< numOfProcesses ; i++)
        {
            if(at[i] <= limit && selectedOrder[i] == -1 )
            {
                if(bt[i] < minBurst || (bt[i] == minBurst && at[i] <= at[index]))  // if burst times are equal check on arrival time also
                {
                    minBurst = bt[i];
                    index = i;
                }
            }
        }

        if(minBurst != INT_MAX)
        {
            selectedOrder[index] = counter++; // here index is the pid of the process and counter is the position at which that process is scheduled
            limit = limit + bt[index];
        }else
        {
            limit++;
            j--;
            continue;
        }

        

    }
}
	


void sjf::calculateWaitingTime()
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
        wt[j]= bt[k] + wt[k];       
      
 
        total+=wt[j];
    }
 
    avwt=(float)total/numOfProcesses; 
}

int sjf :: getPIDfromSchedule(int a)
{
    for(int i =0 ;i <numOfProcesses ;i++)
        if(selectedOrder[i] == a)
            return i;

        return -1;
}

void sjf::showProcesses()
{
	 cout<<"\nProcess\t\tArrivalTime\tBurst Time\tWaiting Time\tTurnaround Time\t Schedule Order";
 
	for(int i=0;i<numOfProcesses;i++)
    {

        cout<<"\nP["<<p[i]+1<<"]"<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<selectedOrder[i];
    }

    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;

}

void sjf :: calculateTurnAroundTime()
{
	int i;
    for(i=0;i<numOfProcesses;i++)
    {
        tat[i]=bt[i]+wt[i];
        avtat+=tat[i];
        
    }
    avtat/=i;
}
