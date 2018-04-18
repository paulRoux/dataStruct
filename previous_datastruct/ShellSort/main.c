#include <stdio.h>
#include <stdlib.h>

#define MAX 12

int main()
{
	int i, j, k, temp, gap;
	int a[MAX] = {20, 11, 24, 2, 54, 23, 4, 12, 56, 32, 16, 35};
	for(gap = MAX/2; gap > 0; gap/=2) //步长的选取
	{
		for(i = 0; i < gap; i++) //直接插入排序的原理
		{
			for(j = i+gap; j < MAX; j+=gap) //每次加上步长，即按列排序
				if(a[j] < a[j-gap])
				{
					temp = a[j];
					k = j-gap;
					while(k >= 0 && a[k] > temp) //记录后移，查找插入位置
					{
						a[k+gap] = a[k];
						k-=gap;
					}
					a[k+gap] =temp; //找到位置插入
				}
		}
	}
	for(i = 0; i < MAX; i++) //循环打印排序好的数组
        printf("%d  ", a[i]);
	return 0;
}
