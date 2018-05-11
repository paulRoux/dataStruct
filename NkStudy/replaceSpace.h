#pragma once
#include <vector>

void replaceSpace(char* str, int length) 
{
	if (length <= 0 || str == NULL) {
		return;
	}

	char *pHead = str;
	int count = 0;
	int len = 0;
	while (*pHead != '\0') {
		//遍历统计空格
		if (*(pHead++) == ' ') {
			count++;
		}
		len++;
	}

	int newLen = len + count * 2;	//新的长度
	char *pEnd = str + newLen;
	
	if (newLen + 1 > length) {
		return;
	}

	while (pHead < pEnd) {
		if (*pHead == ' ') {
			*(pEnd--) = '0';
			*(pEnd--) = '2';
			*(pEnd--) = '%';
		}
		else {
			*(pEnd--) = *pHead;
		}

		--pHead;
	}
}