#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,j,n,TotalHeadMoment=0,initial;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Request sequence\n");
    for(i=0;i<n;i++)
       scanf("%d",&RQ[i]);
    printf("Enter the initial head position\n");
    scanf("%d",&initial);
    printf("Sequence of request access:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",RQ[i]);
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    printf("\nTotal head Moment is %d",TotalHeadMoment);
    return 0;
}
//Enter the number of Requests
//7
//Enter the Request sequence
//82
//170
//43
//140
//24
//16
//190
//Enter the initial head position
//50
//Sequence of request access:
//82170431402416190
//Total head Moment is 642