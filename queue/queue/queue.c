/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月04日 星期六 23时07分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void InitQueue(Queue *Q)
{
    if(Q == NULL){
        exit(1);
    }

    memset(Q->data, 0, MAXSIZE);
    Q->front = 0;
    Q->rear = 0;
}

int GetLengthQueue(Queue Q)
{
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

ElemType GetDataQueue(Queue Q)
{
    return Q.data[Q.front];
}

int InsertQueue(Queue *Q, ElemType e)
{
    if(Q == NULL){
        exit(1);
    }
    if(Q->front == Q->rear+1){
        printf("the queue was fullly!\n");
        return 0;
    }
    
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % MAXSIZE;
    
    return 1;
}

int DelQueue(Queue *Q, ElemType *e)
{
    if(Q == NULL){
        exit(1);
    }
    if(Q->front == Q->rear){
        printf("the queue was empty!\n");
        return 0;
    }

    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % MAXSIZE;

    return 1;
}

void DestroyQueue(Queue *Q)
{
    memset(Q->data, 0, MAXSIZE);
    Q->front = 0;
    Q->rear = 0;
}

int main(void)
{
    Queue queue;
    
    ElemType e;
    printf("Please input the elem: ");
    scanf("%d", &e);
    
    InitQueue(&queue);
    printf("Length: %d\n", GetLengthQueue(queue));
    printf("Data: %d\n", GetDataQueue(queue));
    InsertQueue(&queue, e);
    printf("Length: %d\n", GetLengthQueue(queue));
    printf("Data: %d\n", GetDataQueue(queue));
    DelQueue(&queue, &e);
    printf("Length: %d\n", GetLengthQueue(queue));
    printf("Data: %d\n", GetDataQueue(queue));
    DestroyQueue(&queue);

    return 0;
}
