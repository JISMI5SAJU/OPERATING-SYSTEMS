#include <stdio.h>
void main()
{
    int n,i;
    printf("Enter no of processes");
    scanf("%d",&n);
    int p[n],bt[n],wt[n],tat[n];
    printf("Enter the process and their corresponding burst times\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    tat[0]=bt[0];
    
    float totwt=wt[0],tottat=bt[0];
    
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        totwt=totwt+wt[i];
        tottat=tottat+tat[i];
    }
    printf("process\tbt\twt\ttat\n");
    for(i=0;i<n;i++)
    {
    printf(" %d\t   %d\t  %d\t %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time=%f\nAverage turnaroundTime=%f\n",totwt/n,tottat/n);
}

output:
Enter the number of processses
3
Enter process,burst time and Priority
1 10 2
2 5 1
3 3 3
Process bt      Priority        wt      tat
2       5       1               0       5
1       10      2               5       15
3       3       3               15      18
Average waiting time=6.666667
Average TurnAround time=12.666667

