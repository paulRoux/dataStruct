#include <stdio.h>
#include <stdlib.h>

#define MAX 12

int main()
{
	int i, j, k;
	int a[] = {20, 11, 45, 33, 68, 22, 1, 2, 43, 44, 5, 79};
	for(i = 1; i < MAX; i++) //��0��Ԫ����Ϊ���򣬴ӵ�һ����ʼ
	{
		for(j = i-1; j >= 0; j--)
			if(a[j] < a[i]) //���������е�Ԫ�ؽ��бȽ�
				break;
		if(j != i-1) //���j == i-1��˵����ǰԪ�ص�λ��ǡ�����������е�ĩβ�������ƶ�
		{
			int temp = a[i];
			for(k = i-1; k > j; k--)
				a[k+1] = a[k]; //Ԫ�����κ���
			a[k+1] = temp;
		}
	}
	for(i = 1; i < MAX; i++) //ѭ����ӡ����ŵ�����
        printf("%d  ", a[i]);
	return 0;
}
