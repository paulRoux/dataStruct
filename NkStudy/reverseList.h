#pragma once
#include "include.h"
#include <stack>

//ListNode* ReverseList(ListNode* pHead)
//{
//	if (pHead == NULL || pHead->next == NULL) {
//		return pHead;
//	}
//	std::stack<ListNode*> node;
//	ListNode* pNode = pHead;
//
//	while (pNode->next) {
//		node.push(pNode);
//		pNode = pNode->next;
//	}
//
//	ListNode* tmp = pNode;
//	while (!node.empty()) {
//		pNode->next = node.top();
//		pNode = pNode->next;
//		node.pop();
//	}
//	pNode->next = NULL;
//	return tmp;
//}



ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL) {
		return pHead;
	}

	ListNode* pNode = ReverseList(pHead->next);
	
	//从最后一个节点开始翻转，指针指向前一个节点
	pHead->next->next = pHead;
	pHead->next = NULL;
	
	//一只返回最后一个节点
	return pNode;
}