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

OR
#include <stdio.h>

int main()
{
    int n, m, i, j;

    struct process {
        int psize;
        int flag;
    } p[20];

    struct memory {
        int size;
        int alloc;
    } mem[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the size of processes:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &p[i].psize);
    }

    printf("Enter size of memory blocks:\n");
    for(j = 0; j < m; j++) {
        scanf("%d", &mem[j].size);
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(p[i].psize <= mem[j].size) {
                if(mem[j].alloc == 1) {
                    continue;
                } else {
                    mem[j].alloc = 1;
                    p[i].flag = 1;
                    printf("Process of size %d is allocated for memory location %d\n", p[i].psize, mem[j].size);
                    break; // Exit inner loop once allocation is done
                }
            }
        }
        if(p[i].flag == 0) {
            printf("No memory is allocated for process of size %d\n", p[i].psize);
        }
    }

    return 0;
}
OUTPUT:
Enter the number of processes: 3
Enter the number of memory blocks: 3
Enter the size of processes:
10
9
8
Enter size of memory blocks:
10
3
5
Process of size 10 is allocated for memory location 10
No memory is allocated for process of size 9
No memory is allocated for process of size 8

