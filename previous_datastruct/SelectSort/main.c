#include <stdio.h>
#include <stdlib.h>

#define MAX 12

int main()
{
	int i, j, min, temp;
	int a[MAX] = {20, 11, 24, 2, 54, 23, 4, 12, 56, 32, 16, 35};
	for(i = 0; i < MAX; i++)
	{
		min = i;
		for(j = i+1; j <= MAX; j++)
			if(a[min] > a[j])
				min = j;
		if(i != min)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
	for(i = 0; i < MAX; i++)
		printf("%d  ", a[i]);
	return 0;
}
