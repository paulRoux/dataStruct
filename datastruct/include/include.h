//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_INCLUDE_H
#define DATASTRUCT_INCLUDE_H

#define MAXSIZE 10		/*要排序数组个数的最大值*/

typedef struct
{
	int r[MAXSIZE];		/*存储要排序数组，r[0]作为临时变量或者哨兵*/
	int length;			/*记录顺序表的长度*/
} SqList;


void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

#endif //DATASTRUCT_INCLUDE_H
