#include <iostream>
#include "sjf.h"
 
using namespace std;
 
int main()
{
    // int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
   
    int n;

    cout<<"Enter total number of processes:";
    cin>>n;
    sjf sjfObj(n);
 
    cout<<"\nEnter Process Arrival Time and Burst Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]: \n\t\tarrival time = ";
        int arrTime;
        cin >> arrTime;
        sjfObj.setArrivalTime(i,arrTime);
        int burst;
        cout <<"\n\t\tburst time = ";
        cin>>burst;
        sjfObj.setBurstTime(i,burst);

    }

    sjfObj.scheduleSJF();
    sjfObj.calculateWaitingTime();
    sjfObj.calculateTurnAroundTime();
    sjfObj.showProcesses();
 


    
 
    return 0;
}