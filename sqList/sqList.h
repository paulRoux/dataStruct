/*************************************************************************
	> File Name: sqList.h
	> Author: 
	> Mail: 
	> Created Time: 2017年10月17日 星期二 16时22分32秒
 ************************************************************************/

#ifndef _SQLIST_H
#define _SQLIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
typedef int ElemType;

typedef struct sqlist
{
    ElemType data[MAX];
    int length;
}sqList;

#endif
