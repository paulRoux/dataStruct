#include <stdio.h>

#include "BinaryTree.h"

//
// 队列头文件：Queue.h

#ifndef QUEUE_H
#define QUEUE_H

//
// 队列最大元素个数
#define MAX_QUEUE_SIZE 10

typedef BTree QueueElemType;

//
// 队列结构体
typedef struct tagQueue
{
	BTree *base;
	int front;      // 头指针指示器，若队列不空，则指向队列中队头元素
	int rear;       // 尾指针指示器，若队列不空，则指向队列队尾的下一个位置
}Queue;

//
// 构造一个空的队列
int InitializeQueue(Queue *pQueue);

//
// 判断队列是否为空
int IsQueueEmpty(Queue queue);

//
// 判断队列是否为满
int IsQueueFull(Queue queue);

//
// 入队
int EnQueue(Queue *pQueue, QueueElemType e);

//
// 退队
int DeQueue(Queue *pQueue, QueueElemType *e);

#endif