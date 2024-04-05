#include<stdio.h>
void main()
{
int num;
printf("Enter the number of processes");
scanf("%d",&num);
int p[num];
int shift,temp;
int bt[num],wt[num],tat[num];
int tot_wt=0,tot_tat;
printf("Enter the process names and burst times of each processes\n");
for(int i=0;i<num;i++)
{
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
}
for(int i=0;i<num;i++)
{
for(int j=0;j<i;j++)
{
 if(bt[i]<bt[j])
 {
  temp=bt[i];
  bt[i]=bt[j];
  bt[j]=temp;
  shift=p[i];
  p[i]=p[j];
  p[j]=shift;
 }
 }
 }
wt[0]=0;
tat[0]=bt[0];
tot_tat=tat[0];
printf("Process name:%d\nProcess Burst Time:%d\nProcess Waiting Time:%d\nProcess TuranAroundTime:%d\n",p[0],bt[0],wt[0],tat[0]);
for(int i=1;i<num;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt=tot_wt+wt[i];
tat[i]=tat[i-1]+bt[i];
tot_tat=tot_tat+tat[i];
printf("Process name:%d\nProcess Burst Time:%d\nProcess Waiting Time:%d\nProcess TuranAroundTime:%d\n",p[i],bt[i],wt[i],tat[i]);
}
printf("Total Waiting Time:%d\nTotal TurnAround Time:%d\n",tot_wt,tot_tat);
float av_wt,av_tat;
av_wt=(float)tot_wt/num;
av_tat=(float)tot_tat/num;
printf("Average Waitong Time:%f\nAverage TurnAround Time:%f\n",av_wt,av_tat);
}


