#ifndef SJF 
#define SJF

class sjf
{
	int numOfProcesses;
	int *bt,*wt,*tat,*p,*selectedOrder,*at;
	float avwt,avtat;
public:
	sjf(int numOfProcesses);

	void setBurstTime(int pid , int time);
	void setArrivalTime(int pid,int time);
	void calculateWaitingTime();
	void calculateTurnAroundTime();
	void showProcesses();
	void scheduleSJF();
	int getPIDfromSchedule(int a);

	
};

#endif