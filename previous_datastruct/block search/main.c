#include <stdio.h>
#include <stdlib.h>

#define MAX 5
typedef struct ind
{
	int max; //��Ӧ�������ֵ
	int start; //�������е���ʼλ��
	int end; //��Ӧ���н���λ��
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
	int s = n/MAX; //ÿ��Ĵ�С
	for(i = 0; i < MAX; i++)
	{
		//ǰMAX-1��Ĵ�С����S
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
	int i = 0, j; //i�������������ж�λ�飬j���ڶ�λ����λ��
	while(i < MAX && key > index[i].max)
		i++;
	if(i == MAX)
		return -1;
	j = index[i].start; //�ҵ���Ӧ�鲢����ʼλ�ø�j
	while(j <= index[i].end && a[j] != key)
		j++;
	if(j > index[i].end)
        j = -1;
    return j;
}
