#pragma once
#include "include.h"
#include <iostream>

ListNode* mettingNode(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL) {
		return NULL;
	}

	ListNode* pSlow = pHead->next;
	ListNode* pFast = pSlow->next;

	while (pFast != NULL && pSlow != NULL && pFast != pSlow) {
		if (pFast == pSlow) {
			return pFast;
		}

		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != NULL) {
			pFast = pFast->next;
		}
	}

	return NULL;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meet = mettingNode(pHead);
	if (meet == NULL) {
		return NULL;
	}

	int count = 1;
	ListNode* tmp = meet;
	while (tmp->next != meet) {
		tmp = tmp->next;
		count++;
	}

	tmp = pHead;
	for (int i = 0; i < count; ++i) {
		tmp = tmp->next;
	}

	ListNode* pNode = pHead;
	while (pNode != tmp) {
		pNode = pNode->next;
		tmp = tmp->next;
	}

	return tmp;
}