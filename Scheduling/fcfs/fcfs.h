#ifndef FCFS 
#define FCFS

class fcfs
{
	int numOfProcesses;
	int *bt,*wt,*tat,*selectedOrder,*at;
	float avwt,avtat;
public:
	fcfs(int numOfProcesses);

	void setBurstTime(int pid , int burstTime);
	void setArrivalTime(int pid , int arrvTime);
	void scheduleFCFS();
	void calculateWaitingTime();
	void calculateTurnAroundTime();
	void showProcesses();
	int getPIDfromSchedule(int a);

	
};

#endif