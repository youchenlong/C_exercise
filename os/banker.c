#include<malloc.h>
#include<stdio.h>

#define true 1
#define false 0

typedef struct{
    int n;                  // 进程数量
    int m;                  // 资源种类
    int *Available;         // 每种资源的可用数量
    int **Max;              // 每个进程需要资源的最大数量
    int **Allocation;       // 每个进程已经分配的资源数量
    int **Need;             // 每个进程还需要的资源数量
}DataType;

// int Available[3] = {3, 3, 2};
// int Max[5][3] = {7, 5, 3, 3, 2, 2, 9, 0, 2, 2, 2, 2, 4, 3, 3};
// int Allocation[5][3] = {0, 1, 0, 2, 0, 0, 3, 0, 2, 2, 1, 1, 0, 0, 2};
// int Need[5][3] = {7, 4, 3, 1, 2, 2, 6, 0, 0, 0, 1, 1, 4, 3, 1};

void init_DataType(DataType *d, int n, int m);              // 初始化
int safety_detection(DataType d);                           // 安全检测算法
void resource_request(DataType *d, int i, int *request);    // 资源请求算法

void init_DataType(DataType *d, int n, int m){
    /* n--进程数量 m--资源种类 */
    d->n = n;
    d->m = m;
    d->Available = (int *)malloc(sizeof(int) * m);
    d->Max = (int **)malloc(sizeof(int *) * n);
    d->Allocation = (int **)malloc(sizeof(int *) * n);
    d->Need = (int **)malloc(sizeof(int *) * n);        
    for(int i = 0; i < n; i++){
        d->Max[i] = (int *)malloc(sizeof(int) * m);
        d->Allocation[i] = (int *)malloc(sizeof(int) * m);;
        d->Need[i] = (int *)malloc(sizeof(int) * m);
    }
    
    printf("input Available\n");
    for(int j = 0; j < m; j++){
        // d->Available[j] = Available[j];
        scanf("%d", &d->Available[j]);
    }
    printf("input Max\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // d->Max[i][j] = Max[i][j];
            scanf("%d", &d->Max[i][j]);
        }
    }
    printf("input Allocation\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // d->Allocation[i][j] = Allocation[i][j];
            scanf("%d", &d->Allocation[i][j]);
        }
    }
    printf("input Need\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // d->Need[i][j] = Need[i][j];
            scanf("%d", &d->Need[i][j]);
        }
    }  
}

int safety_detection(DataType d){
    int *Work = (int *)malloc(sizeof(int) * d.m);   // 记录当前可用资源数量
    int *Finish = (int *)malloc(sizeof(int) * d.n); // 记录有哪些进程可以获得需要的所有资源
    // 初始化
    for(int j = 0; j < d.m; j++){
        Work[j] = d.Available[j];
    }
    for(int i = 0; i < d.n; i++){
        Finish[i] = false;
    }
    int i = 0;
    int round = 0;
    while(1){
        // 有两种情况将会退出while循环
        // 情况1、所有进程都能够获得需要的所有资源
        // 情况2、还有进程未获得需要的所有资源，但是系统当前可用资源数量已经无法满足
        if(round == d.n){
            break;
        }
        if(Finish[i] == false){
            int j = 0;
            for(j = 0; j < d.m; j++){
                if(d.Need[i][j] > Work[j]){
                    break;
                }
            }
            if(j == d.m){
                for(int j = 0; j < d.m; j++){
                    Work[j] = Work[j] + d.Allocation[i][j];
                }
                Finish[i] = true;
                round = -1;
            }
        }
        i = (i + 1) % d.n;
        round = round + 1;
    }
    for(int i = 0; i < d.n; i++){
        // 情况2
        if(Finish[i] == false){
            return false;
        }
    }
    // 情况1
    return true;
}

void resource_request(DataType *d, int i, int *request){
    /* i--进程编号  request--请求的各种资源数量 */
    // 步骤1、请求量大于还需要的资源数量
    for(int j = 0; j < d->m; j++){
        if(request[j] > d->Need[i][j]){
            printf("request is larger than need!\n");
            return;
        }
    }
    // 步骤2、请求量大于剩余资源数量
    for(int j = 0; j < d->m; j++){
        if(request[j] > d->Available[j]){
            printf("no enough resource now!\n");
            return;
        }
    }
    // 步骤3、是否分配资源
    // 步骤3.1、如果分配后系统仍然处于安全状态，可以分配
    if(safety_detection(*d)){
        printf("allocate resource succesfully!\n");
        for(int j = 0; j < d->m; j++){
            d->Available[j] = d->Available[j] + request[j];
            d->Allocation[i][j] = d->Allocation[i][j] + request[j];
            d->Need[i][j] = d->Need[i][j] - request[j];
        }
    }
    // 步骤3.2、分配后系统处于不安全状态，不可以分配
    else{
        printf("allocate resource failure!\n");
    }
}


int main(){
    DataType d;
    init_DataType(&d, 5, 3);
    int request[3] = {0, 2, 0};
    resource_request(&d, 0, request);
    return 0;
}