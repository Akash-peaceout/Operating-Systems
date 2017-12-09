#include <iostream>
#include "fcfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
using namespace std;


const int NUM_OF_PROCESSES = 3;
FILE* fp;
fcfs fcfsObj(NUM_OF_PROCESSES);

void fetchBurstTimes();
void fetchArrivalTimes();

void fetchBurstTimes()
{
    cout<<"\nFetching Burst Times from files ...\n";

    for(int i=0;i<NUM_OF_PROCESSES;i++)
    {

        int num;
        char command[100] = "";
        strcat(command,"wc -l ");
        char *numStr = new char[5];
        sprintf(numStr,"%d",i+1);

       
        strcat(command,numStr);
        strcat(command,".txt | awk '{print $1}'");
        fp = popen(command,"r");
        fscanf (fp, "%d", &num);   
        



        cout<<"  P["<<i+1<<"]: "<<num;
       fcfsObj.setBurstTime(i,num);
    }
}

void fetchArrivalTimes()
{
     cout<<"\nFetching Arrival Times from files ...\n";

    for(int i=0;i<NUM_OF_PROCESSES;i++)
    {

        int num;
        char command[100] = "";
        strcat(command,"ls -l ");
        char *numStr = new char[5];
        sprintf(numStr,"%d",i+1);

       
        strcat(command,numStr);
        strcat(command,".txt | awk -F':' '{print $2}' | awk '{print $1}'");
        fp = popen(command,"r");
        fscanf (fp, "%d", &num);   
        



        cout<<"  P["<<i+1<<"]: "<<num;
       fcfsObj.setArrivalTime(i,num);
    }
}
 
int main()
{
   

    fetchBurstTimes();
    fetchArrivalTimes();

    fcfsObj.scheduleFCFS();
    fcfsObj.calculateWaitingTime();
    fcfsObj.calculateTurnAroundTime();
    fcfsObj.showProcesses();

    pclose(fp);
 


    
 
    return 0;
}