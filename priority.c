#include<stdio.h>
void main()
{
    int n,i,j,temp;
    printf("Enter the number of processses\n");
    scanf("%d",&n);
    int p[n],bt[n],wt[n],tat[n],priority[n];
    printf("Enter process,burst time and Priority\n");
    for(i=0;i<n;i++)
    scanf("%d%d%d",&p[i],&bt[i],&priority[i]);
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(priority[j]>priority[j+1]){
                
                temp=priority[j];
                priority[j]=priority[j+1];
                priority[j+1]=temp;
                
                temp=bt[j];
                bt[j]= bt[j+1];
                bt[j+1]=temp;
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
  wt[0]=0,tat[0]=bt[0];
  
  float tot_wt=wt[0],tot_tat=tat[0];
  
  for(i=1;i<n;i++){
      wt[i]=wt[i-1]+bt[i-1];
      tat[i]=tat[i-1]+bt[i];
      tot_wt=tot_wt+wt[i];
      tot_tat=tot_tat+tat[i];
  }
  printf("Process\tbt\tPriority\twt\ttat\n");
  for(int i=0;i<n;i++){
      printf("%d\t%d\t%d\t\t%d\t%d\n",p[i],bt[i],priority[i],wt[i],tat[i]);
  }
  printf("Average waiting time=%f\n",tot_wt/n);
   printf("Average TurnAround time=%f\n",tot_tat/n);
}

OUTPUT:
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
               

   
