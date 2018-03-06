//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_QUICKSORT_H
#define DATASTRUCT_QUICKSORT_H

#include "../include.h"

int Partition(SqList* L, int low, int high)
{
	int pivotkey = L->r[low];

	while (low < high) {
		while (low < high && L->r[high] >= pivotkey) {
			high--;
		}

		swap(L, low, high);

		while (low < high && L->r[low] <= pivotkey) {
			low++;
		}

		swap(L, low, high);
	}

	return low;
}

void QSort(SqList* L, int low, int high)
{
	int pivot;
	if (low < high) {
		pivot = Partition(L, low, high);
		QSort(L, low, pivot-1);
		QSort(L, pivot+1, high);
	}
}

void QuickSort(SqList* L)
{
	QSort(L, 1, L->length);
}


#endif //DATASTRUCT_QUICKSORT_H
