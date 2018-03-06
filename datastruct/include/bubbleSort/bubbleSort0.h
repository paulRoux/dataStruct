//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_BUBBLESORT0_H
#define DATASTRUCT_BUBBLESORT0_H

#include "../include.h"

void BubbleSort0(SqList *L)
{
	int i, j;
	for (i = 1; i < L->length; ++i) {
		for (j = i+1; j < L->length; ++j) {
			if (L->r[i] > L->r[j]) {
				swap(L, i, j);
			}
		}
	}
}


#endif //DATASTRUCT_BUBBLESORT0_H
