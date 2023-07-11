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
please enter number of process: 4

 enter the Burst Time:
p1:5
p2:4
p3:2
p4:1

Process     Burst Time          Waiting Time    Turnaround Time
p4                1                 0                   1
p3                2                 1                   3
p2                4                 3                   7
p1                5                 7                   12

 the average Waiting Time=2.750000
  the average Turnaround Time=5.750000*/
