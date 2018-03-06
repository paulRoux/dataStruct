//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_BUBBLESORT2_H
#define DATASTRUCT_BUBBLESORT2_H

#include "../include.h"


void BubbleSort2(SqList *L)
{
	int i, j;
	bool flag = true;
	for (i = 1; i < L->length && flag; ++i) {
		flag = false;
		for (j = L->length-1; j >= i; --j) {
			if (L->r[j] > L->r[j+1]) {
				swap(L, j, j+1);
				flag = true;
			}
		}
	}
}


#endif //DATASTRUCT_BUBBLESORT2_H
