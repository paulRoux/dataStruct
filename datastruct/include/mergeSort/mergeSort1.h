//
// Created by roux on 18-3-2.
// 非递归的迭代版本
//

#ifndef DATASTRUCT_MERGESORT1_H
#define DATASTRUCT_MERGESORT1_H

#include "../include.h"
#include <malloc.h>

void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k ,l;
	for (j = m+1, k = i; j <= n && i <= m; ++k) {
		if (SR[i] < SR[j]) {
			TR[k] = SR[i++];
		} else {
			TR[k] = SR[j++];
		}
	}

	if (i <= m) {
		for (l = 0; l <= m-i; ++l) {
			TR[k+1] = SR[i+1];
		}
	}

	if (j <= n) {
		for (l = 0; l <= n-j; ++l) {
			TR[k+1] = SR[j+1];
		}
	}
}

void MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1;
	int j;

	while (i <= n- 2*s +1) {
		Merge(SR, TR, i, i+s-1, i+ 2*s -1);
		i = i + 2*s;
	}

	if (i < n-s+1) {
		Merge(SR, TR, i, i+s-1, n);
	} else {
		for (j = i; j <= n; ++j) {
			TR[j] = SR[j];
		}
	}
}

void MergeSort1(SqList* L)
{
	int* TR = (int*)malloc(L->length*sizeof(int));
	int k = 1;

	while (k < L->length) {
		MergePass(L->r, TR, k, L->length);
		k *= 2;
		MergePass(TR, L->r, k, L->length);
		k *= 2;
	}
}


#endif //DATASTRUCT_MERGESORT1_H
