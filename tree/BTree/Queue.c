#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "BinaryTree.h"

//
// 循环队列的实现文件：Queue.c

//
// 构造一个空的队列
int InitializeQueue(Queue *pQueue)
{
	pQueue->base = (QueueElemType *)malloc(sizeof(QueueElemType) * MAX_QUEUE_SIZE);

	// 申请空间失败，则退出程序
	if (pQueue->base == NULL)
	{
		exit(OVERFLOW);
	}

	pQueue->front = pQueue->rear = 0;

	return OK;
}

//
// 判断队列是否为空
// 返回0表示非空，返回非0，表示空
int IsQueueEmpty(Queue queue)
{
	return !(queue.front - queue.rear);
}

//
// 判断队列是否为满
// 返回0表示示满，返回非0，表示已满
int IsQueueFull(Queue queue)
{
	return (queue.rear + 1) % MAX_QUEUE_SIZE == queue.front ;
}

//
// 入队
int EnQueue(Queue *pQueue, QueueElemType e)
{
	if (IsQueueFull(*pQueue))
	{
		printf("队列已经满，不能入队！\n");

		return ERROR;
	}
	else
	{
		pQueue->base[pQueue->rear] = e;
		pQueue->rear = (pQueue->rear + 1) % MAX_QUEUE_SIZE;

		return OK;
	}
}

//
// 退队
int DeQueue(Queue *pQueue, QueueElemType *e)
{
	if (IsQueueEmpty(*pQueue))
	{
		printf("队列为空，不能执行退队操作\n");

		return ERROR;
	}
	else
	{
		*e = pQueue->base[pQueue->front];
		pQueue->front = (pQueue->front + 1) % MAX_QUEUE_SIZE;

		return OK;
	}
}