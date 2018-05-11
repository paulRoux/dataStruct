#pragma once
#include "include.h"
#include <iostream>

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode* pNode = pHead;
	ListNode* pPreNode = NULL;
	
	while (pNode != NULL) {
		ListNode* pNext = pNode->next;
		if (pNext != NULL && pNext->val == pNode->val) {
			int value = pNode->val;
			ListNode* pDelete = pNode;

			while (pDelete != NULL && pDelete->val == value) {
				pNext = pDelete->next;
				delete pDelete;
				pDelete = NULL;
				pDelete = pNext;
			}

			if (pPreNode == NULL) {
				pHead = pNext;
			}
			else {
				pPreNode->next = pNext;
			}

			pNode = pNext;
		}
		else {
			pPreNode = pNode;
			pNode = pNode->next;
		}
	}

	return pHead;
}