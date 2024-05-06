#include<stdio.h>
void main()
{
    int n;
    printf("Enter the no of processes");
    scanf("%d",&n);
    struct process{
        int pid;
        int psize;
        int flag;
    }p[n];
    struct memory{
        int size;
        int alloc;
    }m[10];
    printf("Enter the process size");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].psize);
    }
    printf("Enter the size of memory block");
    for(int i=0;i<n;i++){
        scanf("%d",&m[i].size);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
        if(p[i].psize<=m[i].size){
            if(m[i].alloc==1){
                continue;
            }else{
                m[i].alloc=1;
                p[i].flag=1;
                printf("Process of size %d is allocated in memory location %d\n",p[i].psize,m[i].size);
            }
        }
        } 
    }
    for(int i=0;i<n;i++)
    if(p[i].flag==0){
        printf("No space for process of size  %d to be allocated\n",p[i].psize);
    }
}

OUTPUEnter the no of processes3
Enter the process size10
9
8
Enter the size of memory block10
8
7
Process of size 10 is allocated in memory location 10
No space for process of size  9 to be allocated
No space for process of size  8 to be allocated

