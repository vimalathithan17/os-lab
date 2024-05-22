#include<stdio.h>
#include<stdlib.h>
typedef struct Process { 
	int pid; // Process ID 
	int bt; // CPU Burst time required 
	int priority;// Priority of this process 
  int at;
 
} process;
void int_process(process * p,int pid, int bt,int at, int priority) 
{ 
		p->pid = pid; 
		p->bt = bt; 
		p->priority = priority; 
    p->at=at;
}
 
	// Function to find the waiting time for all 
	// processes 
	void findWaitingTime(process proc[], int n, int wt[]) 
	{ 
    int *service=(int*)calloc(n, sizeof(int));
    service[0]=proc[0].at;
  
		// waiting time for first process is 0 
		wt[0] = 0; 

		// calculating waiting time 
		for (int i = 1; i < n; i++){ 
      service[i]=proc[i-1].bt+service[i-1];
			wt[i] = service[i]-proc[i].at; 
      if(wt[i]<0){
      wt[i]=0;
      }  
    }
	} 

	// Function to calculate turn around time 
	void findTurnAroundTime(process proc[], int n, 
								int wt[], int tat[]) 
	{ 
		// calculating turnaround time by adding 
		// bt[i] + wt[i] 
		for (int i = 0; i < n; i++) 
			tat[i] = proc[i].bt + wt[i]; 
	} 

	// Function to calculate average time 
	void findavgTime(process proc[], int n) 
	{ 
		int* wt,*tat,total_wt = 0, total_tat = 0;
    wt=(int *)calloc(n,sizeof(int));
    tat=(int *)calloc(n, sizeof(int));

		// Function to find waiting time of all processes 
		findWaitingTime(proc, n, wt); 

		// Function to find turn around time for all 
		// processes 
		findTurnAroundTime(proc, n, wt, tat); 
    int *stime,*ctime;
    stime=(int*)calloc(n, sizeof(int));
    ctime=(int*)calloc(n, sizeof(int));
    stime[0]=proc[0].at;
    ctime[0]=stime[0]+tat[0];
    for(int i=1;i<n;i++){
      stime[i]=ctime[i-1];
      ctime[i]=stime[i]+tat[i]-wt[i];
    }


    
		// Display processes along with all details 
	printf("\nProcesses_no\tstart_time\tCompletion_time\tTurn_around_time\tWaiting_time\n"); 

		// Calculate total waiting time and total turn 
		// around time 
		for (int i = 0; i < n; i++) { 
			total_wt = total_wt + wt[i]; 
			total_tat = total_tat + tat[i]; 
			printf(" %d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", proc[i].pid,stime[i], ctime[i], tat[i],wt[i]); 
		} 
		printf("\nAverage waiting time =%g\n", (float)total_wt / (float)n);
		printf("\nAverage turn around time = %g\n",(float)total_tat / (float)n); 
	} 

void priorityScheduling(process proc[], int n) 
{ 

		// Sort processes by priority 
	for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(proc[j].at>proc[j+1].at || (proc[j].at==proc[j+1].at && proc[j].priority>proc[j+1].priority)){
    
          process temp=proc[j];
          proc[j]=proc[j+1];
          proc[j+1]=temp;
      } 
    }
  } 
	printf( "Order in which processes gets executed \n"); 
	for (int i = 0; i < n; i++) {
			printf("%d ",proc[i].pid ); 
  }

		findavgTime(proc, n); 
} 

	// Driver code 
void main() 
{  
		int n;
    printf("Enter the number of process:");
    scanf("%d",&n);
		process *proc =(process *)calloc(n, sizeof(process));
    for(int i=0;i<n;i++){
      int priority,bt,at;
      printf("Enter arival time of p%d:",i);
      scanf("%d",&at);
      printf("Enter burst time for p%d:",i);
      scanf("%d",&bt);
      printf("Enter the priority of p%d:",i);
      scanf("%d",&priority); 
      int_process(&(proc[i]),i,bt,at,priority);
    }  
		priorityScheduling(proc, n); 
} 

// This code is c
