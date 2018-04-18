#include <stdio.h>
#include <stdlib.h>

#define MAX 12
void HeapSort();

int main()
{
	int i;
	int a[MAX] = {20, 11, 24, 2, 54, 23, 4, 12, 56, 32, 16, 35};
	HeapSort(a, MAX);
	for(i = 0; i < MAX; i++)
		printf("%d  ", a[i]);
	return 0;
}

void HeapAdjust(int a[], int i, int n) //构建大顶堆
{
	int j, t;
	while(2*i+1 < n) // 判断是否第S个节点是否有右子树
	{
		j = 2*i+1;
		if(j+1 < n) //判断判断右子树是否为最后节点
			if(a[j] < a[j+1]) //判断是否左子节点小于右子节点
				j++; //j指向右子节点
		if(a[i] < a[j]) //判断是否为大顶堆,若不是则进行自上往下替换排序
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i = j;
		}
		else
			break;
	}
}

void HeapSort(int a[], int n)
{
	int i, t;
	for(i = n/2-1; i >= 0; i--)
		HeapAdjust(a, i, n); //构建大顶堆
	for(i = n-1; i > 0; i--) //排序并且重新调整为大顶堆
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		HeapAdjust(a, 0, i);
	}
}
