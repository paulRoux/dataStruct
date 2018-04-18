#include <stdio.h>
#include <stdlib.h>

#define MAX 12

int main()
{
	int i, j, k;
	int a[] = {20, 11, 45, 33, 68, 22, 1, 2, 43, 44, 5, 79};
	for(i = 1; i < MAX; i++) //第0个元素认为有序，从第一个开始
	{
		for(j = i-1; j >= 0; j--)
			if(a[j] < a[i]) //与有序序列的元素进行比较
				break;
		if(j != i-1) //如果j == i-1，说明当前元素的位置恰巧在有序序列的末尾，无需移动
		{
			int temp = a[i];
			for(k = i-1; k > j; k--)
				a[k+1] = a[k]; //元素依次后移
			a[k+1] = temp;
		}
	}
	for(i = 1; i < MAX; i++) //循环打印排序号的数组
        printf("%d  ", a[i]);
	return 0;
}
