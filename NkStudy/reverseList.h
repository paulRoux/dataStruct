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
	
	//�����һ���ڵ㿪ʼ��ת��ָ��ָ��ǰһ���ڵ�
	pHead->next->next = pHead;
	pHead->next = NULL;
	
	//һֻ�������һ���ڵ�
	return pNode;
}