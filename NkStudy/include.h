#pragma once

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(0) {}
};
