#include<stdio.h>
void printer(int processes[],int n,int burst_time[],int arrival_time[])
{
    int WT[n],TAT[n],total_WT=0,total_TAT=0,completion_time[n];
    for (int i = 0; i < n; i++)//calculating times
    {
        if(i==0)
        {
            WT[0]=0;
            completion_time[0]=burst_time[0]+arrival_time[0];
            TAT[0]=completion_time[0]-arrival_time[0];
            total_TAT=TAT[0];
            continue;
        }
        if(completion_time[i-1]<arrival_time[i])
        {
            completion_time[i]=arrival_time[i]+burst_time[i];
        }
        else
        {
            completion_time[i]=completion_time[i-1]+burst_time[i];
        }
        TAT[i]=completion_time[i]-arrival_time[i];
        total_TAT+=TAT[i];
        WT[i]=TAT[i]-burst_time[i];
        total_WT+=WT[i];
    }
    printf("Processes\tAT\tBT\tWT\tTAT\tCT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n",processes[i],arrival_time[i],burst_time[i],WT[i],TAT[i],completion_time[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("\n");
}
void sjf(int processes[],int n,int burst_time[],int arrival_time[])
{
    int WT[n],TAT[n],total_WT=0,completion_time[n],total_TAT=0;
    for (int i = 0; i < n; i++)
    {
        int shortest_job_index=i;
        for (int j = i+1; j < n; j++)
        {
            if (burst_time[j]<burst_time[shortest_job_index])
            {
                shortest_job_index=j;
            }
        }
        int temp=burst_time[i];
        burst_time[i]=burst_time[shortest_job_index];
        burst_time[shortest_job_index]=temp;
        
        temp=processes[i];
        processes[i]=processes[shortest_job_index];
        processes[shortest_job_index]=temp;

        temp=arrival_time[i];
        arrival_time[i]=arrival_time[shortest_job_index];
        arrival_time[shortest_job_index]=temp;
    }
    printf("SJF agorithm\n");
    printer(processes,n,burst_time,arrival_time);
}
void main()
{
    int n;
    int quantum;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int processes[n],burst_time[n],arrival_time[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time for process %d:",i+1);
        scanf("%d",&arrival_time[i]);
        printf("Enter the Burst time for processes %d:",i+1);
        scanf("%d",&burst_time[i]);
        processes[i]=i+1;
    }
    sjf(processes,n,burst_time,arrival_time);
}