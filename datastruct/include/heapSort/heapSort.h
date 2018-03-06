//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_HEAPSORT_H
#define DATASTRUCT_HEAPSORT_H

#include "../include.h"

void HeapAdjust(SqList* L, int s, int m)
{
	/*调整s->m范围，使之成为大顶堆*/
	int temp, j;
	temp = L->r[s];
	for (j = 2*s; j <= m; j *= 2) {
		/*j的取值为完全二叉树的性质：左孩子为2j，右孩子为2j+1*/
		if (j < m && L->r[j] < L->r[j+1]) {
			++j;
		}

		if (temp >= L->r[j]) {
			break;
		}

		L->r[s] = L->r[j];
		s = j;
	}

	L->r[s] = temp;
}

void HeapSort(SqList *L)
{
	int i;

	/*构造大顶堆*/
	for (i = L->length/2; i > 0; --i) {
		/*i的取值的规律是：都为有孩子的节点*/
		HeapAdjust(L, i, L->length);
	}

	/*排序*/
	for (i = L->length; i > 1; --i) {
		swap(L, 1, i);
		HeapAdjust(L, 1, i-1);
	}
}


#endif //DATASTRUCT_HEAPSORT_H
