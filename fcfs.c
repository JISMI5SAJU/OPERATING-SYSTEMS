#include<stdio.h>
void main()
{
int n;
printf("Enter the no of processes");
scanf("%d",&n);
int p[n];
int bt[n],wt[n],tat[n];
int tot_wt=0,tot_tat;
printf("Enter the process names and burst time of each processses\n");
for(int i=0;i<n;i++)
{
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
}
wt[0]=0;
tat[0]=bt[0];
tot_tat=tat[0];
printf("Process name:%d\nProcess Burst Time:%d\nProcess Waiting Time:%d\nProcess TuranAroundTime:%d\n",p[0],bt[0],wt[0],tat[0]);
for(int i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt=tot_wt+wt[i];
tat[i]=tat[i-1]+bt[i];
tot_tat=tot_tat+tat[i];
printf("Process name:%d\nProcess Burst Time:%d\nProcess Waiting Time:%d\nProcess TuranAroundTime:%d\n",p[i],bt[i],wt[i],tat[i]);
}
printf("Total Waiting Time:%d\nTotal TurnAround Time:%d\n",tot_wt,tot_tat);
float av_wt,av_tat;
av_wt=(float)tot_wt/n;
av_tat=(float)tot_tat/n;
printf("Average Waitong Time:%f\nAverage TurnAround Time:%f\n",av_wt,av_tat);
}

