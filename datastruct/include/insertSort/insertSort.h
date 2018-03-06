//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_INSERTSORT_H
#define DATASTRUCT_INSERTSORT_H

#include "../include.h"

void InsertSort(SqList *L)
{
	int i, j;
	for (i = 2; i < L->length; ++i) {
		if (L->r[i] < L->r[i-1]) {
			L->r[0] = L->r[i];

			for (j = i-1; L->r[j] > L->r[0]; --j) {
				L->r[j+1] = L->r[j];
			}

			L->r[j+1] = L->r[0];
		}
	}
}


#endif //DATASTRUCT_INSERTSORT_H
