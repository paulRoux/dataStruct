//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_SELECTSORT_H
#define DATASTRUCT_SELECTSORT_H

#include "../include.h"

void SelectSort(SqList *L)
{
	int i, j, min;
	for (i = 1; i < L->length; ++i) {
		min = i;
		for (j = i+1; j <= L->length ; ++j) {
			if (L->r[min] > L->r[j]) {
				min = j;
			}

			if (i != min) {
				swap(L, i, min);
			}
		}
	}
}

#endif //DATASTRUCT_SELECTSORT_H
