#include <iostream>
#include "fcfs.h"
 
using namespace std;
 
int main()
{
    // int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
   
    int n;

    cout<<"Enter total number of processes:";
    cin>>n;
    fcfs fcfsObj(n);
 
    cout<<"\nEnter Process Details : \n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:\n";
        cout << "Arrival Time : "; 
        int arrTime;
        cin >> arrTime;
        fcfsObj.setArrivalTime(i,arrTime);
         cout << "Burst Time : "; 
        int burst;
        cin >> burst;
       fcfsObj.setBurstTime(i,burst);
    }

    fcfsObj.scheduleFCFS();
    fcfsObj.calculateWaitingTime();
    fcfsObj.calculateTurnAroundTime();
    fcfsObj.showProcesses();

    return 0;
}