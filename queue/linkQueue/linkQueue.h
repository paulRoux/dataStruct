/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月04日 星期六 23时07分50秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

#define MAXSIZE 1024
typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node* next;
}Queue, *LinkQueuePtr;

typedef struct{
    LinkQueuePtr front, rear;
}LinkQueue;

void InitQueue(LinkQueue *Q);

int GetLengthQueue(LinkQueue *Q);

int GetDataQueue(LinkQueue *Q);

int InsertQueue(LinkQueue *Q, ElemType e);

int DelQueue(LinkQueue *Q, ElemType *e);

void DestroyQueue(LinkQueue *Q);

#endif
