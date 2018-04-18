#include <stdio.h>
#include <stdlib.h>

#define MAX 5
typedef struct ind
{
	int max; //对应块中最大值
	int start; //索引表中的起始位置
	int end; //对应块中结束位置
}Ind;

Ind index[MAX];

void creatBlock();
int blockSearch();

int main()
{
	int k;
	int a[] = {20, 11, 15, 6, 3, 33, 42, 38, 24, 27, 47, 58, 74, 49, 80, 59};
	creatBlock(a, 15);
	k = blockSearch(58, a);
	if(k != -1)
		printf("%d\n", k);
	else
		printf("------Not Find------");
    printf("%d", a[k]);
	return 0;
}

void creatBlock(int a[], int n)
{
	int i, j=0, k, m=0;
	int s = n/MAX; //每块的大小
	for(i = 0; i < MAX; i++)
	{
		//前MAX-1块的大小都是S
		if(i < MAX-1)
		{
			index[i].start = j;
			index[i].end = j+s-1;
			j+=s;
		}
		else
		{
			index[i].start = j;
			index[i].end = n-1;
		}
		for(k = index[i].start; k <= index[i].end; k++)
		{
			m = a[k];
			if(a[k+1] > m)
				m = a[k+1];
		}
		index[i].max = m;
	}
}

int blockSearch(int key, int a[])
{
	int i = 0, j; //i用于在索引表中定位块，j用于定位其块的位置
	while(i < MAX && key > index[i].max)
		i++;
	if(i == MAX)
		return -1;
	j = index[i].start; //找到对应块并把起始位置给j
	while(j <= index[i].end && a[j] != key)
		j++;
	if(j > index[i].end)
        j = -1;
    return j;
}
