/*************************************************************************
	> File Name: staticList.h
	> Author: 
	> Mail: 
	> Created Time: 2017年10月19日 星期四 19时55分12秒
 ************************************************************************/

#ifndef _STATICLIST_H
#define _STATICLIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType data;
    int cur;
} Component,StaticList[MAXSIZE];

int InitList(StaticList space);

int Malloc_SLL(StaticList space);

int InsertList(StaticList L, int i, ElemType e);

void Free_SSL(StaticList space, int k);

int LengthList(StaticList L);

int DelList(StaticList L, int i);

#endif
