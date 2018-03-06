//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_BUBBLESORT1_H
#define DATASTRUCT_BUBBLESORT1_H

#include "../include.h"


void BubbleSort1(SqList *L)
{
	int i, j;
	for (i = 1; i < L->length; ++i) {
		for (j = L->length-1; j >= i; --j) {
			if (L->r[j] > L->r[j+1]) {
				swap(L, j, j+1);
			}
		}
	}
}


#endif //DATASTRUCT_BUBBLESORT1_H
