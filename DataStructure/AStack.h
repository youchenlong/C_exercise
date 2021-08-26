#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int size;       // 栈大小
    int sp;         // 栈指针
    int *array;     // 存放栈内元素
}AStack;

void create(AStack *s, int size);        // 创建栈
void clear(AStack *s);                   // 清空栈
void push(AStack *s, int val);           // 入栈
int pop(AStack *s);                      // 出栈
int topValue(AStack s);                  // 栈顶元素
int length(AStack s);                    // 已有元素的长度


void create(AStack *s, int size){
    s->size = size;
    s->sp = size;
    s->array = (int *)malloc(sizeof(int)*size);
}

void clear(AStack *s){
    s->sp = s->size;
}

void push(AStack *s, int val){
    if(s->sp == 0){
        printf("AStack is full");
        exit(0);
    }
    s->sp--;
    s->array[s->sp] = val;
}

int pop(AStack *s){
    if(s->sp == s->size){
        printf("AStack is empty");
        exit(0);
    }
    int val = s->array[s->sp];
    s->sp++;
    return val;
}

int topValue(AStack s){
    return s.array[s.sp];
}

int length(AStack s){
    return s.size - s.sp;
}