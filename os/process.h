#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int pid;                                // 进程号
    int arrival_time;                       // 到达时间
    int remaining_execution_time;           // 剩余执行时间
    int execution_time;                     // 已经执行时间
    int waiting_time;                       // 已经等待时间
    int priority;                           // 优先级(采用低数字表示高优先级)
}process;

process create_process();                   // 创建一个进程
void running_process(process *p);           // 运行一个时间片
void waiting_process(process *p);           // 等待一个时间片

process create_process(){
    printf("creating a process....\n");
    process p;
    printf("input pid of process: ");
    scanf("%d", &p.pid);
    printf("input arrival time of the process: ");
    scanf("%d", &p.arrival_time);
    printf("input remaining execution time of the process: ");
    scanf("%d", &p.remaining_execution_time);
    if(p.remaining_execution_time <= 0){
        printf("create process error! Remaining execution time <= 0");
        exit(-1);
    }
    printf("input priority of the process: ");
    scanf("%d", &p.priority);
    p.execution_time = 0;
    p.waiting_time = 0;
    return p;
}

void running_process(process *p){
    printf("running process %d......\n", p->pid);
    // 更新剩余执行时间和已经执行时间
    p->remaining_execution_time--;
    p->execution_time++;
}

void waiting_process(process *p){
    // 更新等待时间
    p->waiting_time++;
}