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

typedef struct{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

void InitQueue(Queue *Q);

int GetLengthQueue(Queue Q);

int GetDataQueue(Queue Q);

int InsertQueue(Queue *Q, ElemType e);

int DelQueue(Queue *Q, ElemType *e);

void DestroyQueue(Queue *Q);

#endif
