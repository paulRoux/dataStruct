#pragma once
#include "include.h"
#include <iostream>

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL) {
		return NULL;
	}

	ListNode* pNode1 = pHead1;
	ListNode* pNode2 = pHead2;

	int count1 = 0;
	while (pNode1) {
		pNode1 = pNode1->next;
		count1++;
	}

	int count2 = 0;
	while (pNode2) {
		pNode2 = pNode2->next;
		count2++;
	}

	int num;
	bool flag = false;
	if (count1 > count2) {
		num = count1 - count2;
	}
	else {
		num = count2 - count1;
		flag = true;
	}


	pNode1 = pHead1;
	pNode2 = pHead2;
	for (int i = 0; i < num; ++i) {
		if (flag == false ) {
			pNode1 = pNode1->next;
		}
		else {
			pNode2 = pNode2->next;
		}
	}

	while (pNode1 != NULL && pNode2 != NULL) {
		if (pNode1 == pNode2) {
			return pNode1;
		}

		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}

	return NULL;
}