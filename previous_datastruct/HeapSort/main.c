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

void HeapAdjust(int a[], int i, int n) //�����󶥶�
{
	int j, t;
	while(2*i+1 < n) // �ж��Ƿ��S���ڵ��Ƿ���������
	{
		j = 2*i+1;
		if(j+1 < n) //�ж��ж��������Ƿ�Ϊ���ڵ�
			if(a[j] < a[j+1]) //�ж��Ƿ����ӽڵ�С�����ӽڵ�
				j++; //jָ�����ӽڵ�
		if(a[i] < a[j]) //�ж��Ƿ�Ϊ�󶥶�,��������������������滻����
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
		HeapAdjust(a, i, n); //�����󶥶�
	for(i = n-1; i > 0; i--) //���������µ���Ϊ�󶥶�
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		HeapAdjust(a, 0, i);
	}
}
