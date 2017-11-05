/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月04日 星期六 23时07分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkQueue.h"

void InitQueue(LinkQueue *Q)
{
    if(Q == NULL){
        exit(1);
    }
    
    Q->front = Q->rear = (LinkQueuePtr)malloc(sizeof(Queue));
    Q->front->next = NULL;
    Q->front->data = 0;
}

int GetLengthQueue(LinkQueue *Q)
{
    if(Q->front == Q->rear){
        return 0;
    }

    int count = 0;
    LinkQueuePtr tmp = Q->front;
    while(tmp->next != NULL && tmp != Q->rear){
        count++;
        tmp = tmp->next;
    }

    return count;
}

ElemType GetDataQueue(LinkQueue *Q)
{
    if(Q->front->next == NULL){
        return -1;
    }
    return Q->front->next->data;
}

int InsertQueue(LinkQueue *Q, ElemType e)
{
    if(Q == NULL){
        exit(1);
    }
    
    LinkQueuePtr tmp = (LinkQueuePtr)malloc(sizeof(Queue));
    if(!tmp){
        exit(1);
    }
    tmp->data = e;
    tmp->next = NULL;
    Q->rear->next = tmp;
    Q->rear = tmp;

    return 1;
}

int DelQueue(LinkQueue *Q, ElemType *e)
{
    if(Q == NULL){
        exit(1);
    }
    if(Q->front == Q->rear){
        printf("the queue was empty!\n");
        return 0;
    }

    LinkQueuePtr tmp;
    tmp = Q->front->next;
    *e = tmp->data;
    Q->front->next = Q->front->next->next;
    
    if(Q->rear == Q->front->next){
        Q->rear = Q->front;
    }
    
    free(tmp);

    return 1;
}

void DestroyQueue(LinkQueue *Q)
{
    LinkQueuePtr tmp;
    while(Q->front->next != NULL){
        tmp = Q->front->next;
        Q->front->next = Q->front->next->next;
        free(tmp);
    }    
}

int main(void)
{
    LinkQueue queue;
    
    ElemType e;
    printf("Please input the elem: ");
    scanf("%d", &e);
    
    InitQueue(&queue);
    printf("Length: %d\n", GetLengthQueue(&queue));
    printf("Data: %d\n", GetDataQueue(&queue));
    InsertQueue(&queue, e);
    printf("Length: %d\n", GetLengthQueue(&queue));
    printf("Data: %d\n", GetDataQueue(&queue));
    DelQueue(&queue, &e);
    printf("Length: %d\n", GetLengthQueue(&queue));
    printf("Data: %d\n", GetDataQueue(&queue));
    DestroyQueue(&queue);

    return 0;
}
