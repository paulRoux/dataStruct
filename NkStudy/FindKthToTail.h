#pragma once
#include "include.h"
#include <iostream>

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0) {
		return NULL;
	}

	ListNode* pNode = pListHead;
	ListNode* tmp = pListHead;
	for (int i = 1; i < k; ++i) {
		if (pNode->next != NULL) {
			pNode = pNode->next;
		}
		else {
			return NULL;
		}
	}

	while (pNode->next) {
		pNode = pNode->next;
		tmp = tmp->next;
	}

	return tmp;
}