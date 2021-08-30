#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char *studentID;
    char *studentName;
    char *sex;
    int age;
    char *class;
}DataType;

typedef struct node{
    DataType value;
    struct node *next;
}node;

typedef struct{
    node *head;         // 头节点
    node *tail;         // 尾节点
    node *curr;         // 当前节点(为了方便进行插入或删除操作，实际上操作的是当前节点的下一个节点)
    int count;          // 链表当前节点数
}LList;

LList create();                                         // 创建链表
void clear(LList *llist);                               // 清空链表
void append(LList *llist, DataType value);              // 在链表末尾添加节点
void insert(LList *llist, DataType value);              // 在当前位置插入节点
DataType delete(LList *llist);                          // 在当前位置删除节点
void moveToStart(LList *llist);                         // 移到表头
void moveToEnd(LList *llist);                           // 移到表位
void moveToPos(LList *llist, int pos);                  // 移到指定位置(pos从0开始)
void next(LList *llist);                                // 当前位置向后移
DataType getValue(LList llist);                         // 获取当前节点的元素
void traverse(LList llist);                             // 遍历链表


void init(LList *llist){
    llist->count = 0; 
    // 为了减少判定链表是否为空的代码，加入一个空节点，但不修改链表节点数count的值
    node *n = (node *)malloc(sizeof(node));
    n->next = NULL;
    // 头节点，尾节点，当前节点指向同一个节点
    llist->head = n;
    llist->curr = n;
    llist->tail = n;
}

void removeall(LList *llist){
    // 只要链表不为空，不断地从头删除节点
    while(llist->head != NULL){
        llist->curr = llist->head;
        llist->head = llist->head->next;
        free(llist->curr);
    }
}

LList create(){  
    LList *llist = (LList *)malloc(sizeof(LList));
    init(llist);
    return *llist;
}

void clear(LList *llist){
    removeall(llist);
    init(llist);
}

void append(LList *llist, DataType value){
    node *n = (node *)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    // 让链表尾节点指向它(注意指针与实际物理内存的联系，不然会产生疑惑)
    llist->tail->next = n;   
    llist->tail = llist->tail->next;
    llist->count++;
}

void insert(LList *llist, DataType value){
    node *n = (node *)malloc(sizeof(node));
    n->value = value;
    // 该节点下一个节点指向当前节点的下一个节点
    n->next = llist->curr->next;
    // 当前节点的下一个节点指向该节点
    llist->curr->next = n;
    // 如果当前节点为尾节点，那么尾节点需要指向该节点(尾节点始终应该在链表末尾)
    if(llist->curr == llist->tail){
        llist->tail = llist->curr->next;
    }
    llist->count++;
}

DataType delete(LList *llist){
    DataType value = getValue(*llist);
    // 待删除的节点
    node *n = llist->curr->next;
    // 如果待删除的节点为尾节点，那么尾节点需要指向当前节点(因为尾节点不应该被释放)
    if(llist->curr->next == llist->tail){
        llist->tail = llist->curr;
    }
    // 链表跳过待删除节点
    llist->curr->next = llist->curr->next->next;
    // 释放待删除节点
    free(n);
    llist->count--;
    return value;
}

void moveToStart(LList *llist){    
    llist->curr = llist->head;
}

void moveToEnd(LList *llist){
    llist->curr = llist->tail;
}

void moveToPos(LList *llist, int pos){
    if(pos < 0 || pos >= llist->count){
        printf("position out of range");
        exit(0);
    }
    moveToStart(llist);
    int i = 0;
    while(i < pos){
        llist->curr = llist->curr->next;
        i++;
    }
}

void next(LList *llist){
    if(llist->curr != llist->tail){
        llist->curr = llist->curr->next;
    }
}

DataType getValue(LList llist){
    if(llist.curr->next == NULL){
        printf("No value");
        exit(0);
    }
    // 返回的是当前节点的下一个节点的值
    return llist.curr->next->value;
}

void traverse(LList llist){
    for(moveToStart(&llist); llist.curr != llist.tail; next(&llist)){
        printf("%s\t", getValue(llist).studentID);
        printf("%s\t", getValue(llist).studentName);
        printf("%s\t", getValue(llist).sex);
        printf("%d\t", getValue(llist).age);
        printf("%s\n", getValue(llist).class);
    }
}