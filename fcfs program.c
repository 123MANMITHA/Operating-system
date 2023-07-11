#include<stdio.h>
int main()
{
    char pn[10][10];
    int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,n;
    int totwt=0,tottat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the Process name,Arrival time and Burst time:");
        scanf("%zs%d%d",&pn[i],&arr[i],&bur[i]);
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
        star[i]=arr[i];
        wt[i]=star[i]-arr[i];
        finish[i]=star[i]+bur[i];
        tat[i]=finish[i]-arr[i];
        }
        else
        {
            star[i]=finish[i-1];
            wt[i]=star[i]-arr[i];
            finish[i]=star[i]+bur[i];
            tat[i]=finish[i]-arr[i];

        }
    }
    printf("\nPName Arrtime Burstime Start TAT Finish");
    for(i=0;i<n;i++)
    {
        printf("\n%s\t%6d\t\t%6d\t%6d\t%6d\t%6d",pn[i],arr[i],bur[i],star[i],tat[i],finish[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
    printf("\nAverage Waiting time:%f",(float)totwt/n);
    printf("\nAverage turn around time:%f",(float)tottat/n);
}

OUTPUT
Enter the number of processes: 4
Enter the arrival time for process 1:0
Enter the Burst time for processes 1:5
Enter the arrival time for process 2:1
Enter the Burst time for processes 2:3
Enter the arrival time for process 3:2
Enter the Burst time for processes 3:4
Enter the arrival time for process 4:4
Enter the Burst time for processes 4:1
FCFS agorithm
Processes       AT      BT      WT      TAT     CT      RT
1               0       5       0       5       5       0
2               1       3       4       7       8       4
3               2       4       6       10      12      6
4               4       1       8       9       13      8
AVG waiting time: 4.500000
AVG turnaround time: 7.750000*/
