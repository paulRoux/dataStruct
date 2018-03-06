//
// Created by roux on 18-3-2.
//

#ifndef DATASTRUCT_SHELLSORT_H
#define DATASTRUCT_SHELLSORT_H

#include "../include.h"

void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;

	do {
		increment = increment/3 + 1;		/*增量序列*/
		for (i = increment; i < L->length; ++i) {
			if (L->r[i] < L->r[i-increment]) {
				L->r[0] = L->r[i];

				for (j = i-increment; j > 0 && L->r[0] < L->r[j] ; j -= increment) {
					L->r[j+increment] = L->r[j];
				}

				L->r[j+increment] = L->r[0];
			}
		}
	} while (increment > 1);
}


#endif //DATASTRUCT_SHELLSORT_H
