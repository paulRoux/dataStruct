/*************************************************************************
	> File Name: linkList.h
	> Author: 
	> Mail: 
	> Created Time: 2017年10月18日 星期三 19时13分00秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

typedef struct node *LinkList;

//创建新链表
int CreateList(LinkList *L);

//获取链表的长度
int GetLength(LinkList L);

//获取链表的元素
int GetList(LinkList L, int i, ElemType *e);

//对链表插入元素
int InsertList(LinkList *L, int i, ElemType e);

//删除链表的元素
int DelList(LinkList *L, int i, ElemType *e);

//删除链表
int ClearList(LinkList *L);

#endif
