#pragma once
#include "include.h"
#include <iostream>
#include <vector>
#include <stack>

//std::vector<int> printListFromTailToHead(ListNode* head)
//{
//	std::vector<int> value;
//	if (head == NULL) {
//		return value;
//	}
//
//	ListNode* pNode = head;
//	while (pNode != NULL) {
//		value.insert(value.begin(), pNode->val);
//		pNode = pNode->next;
//	}
//
//	return value;
//}

std::vector<int> printListFromTailToHead(ListNode* head)
{
	std::vector<int> value;
	if (head == NULL) {
		return value;
	}

	std::stack<int> node;
	ListNode* pNode = head;
	while (pNode != NULL) {
		node.push(pNode->val);
		pNode = pNode->next;
	}

	while (!node.empty()) {
		value.push_back(node.top());
		node.pop();
	}

	return value;
}