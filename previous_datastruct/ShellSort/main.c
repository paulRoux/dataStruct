#include <stdio.h>
#include <stdlib.h>

#define MAX 12

int main()
{
	int i, j, k, temp, gap;
	int a[MAX] = {20, 11, 24, 2, 54, 23, 4, 12, 56, 32, 16, 35};
	for(gap = MAX/2; gap > 0; gap/=2) //������ѡȡ
	{
		for(i = 0; i < gap; i++) //ֱ�Ӳ��������ԭ��
		{
			for(j = i+gap; j < MAX; j+=gap) //ÿ�μ��ϲ���������������
				if(a[j] < a[j-gap])
				{
					temp = a[j];
					k = j-gap;
					while(k >= 0 && a[k] > temp) //��¼���ƣ����Ҳ���λ��
					{
						a[k+gap] = a[k];
						k-=gap;
					}
					a[k+gap] =temp; //�ҵ�λ�ò���
				}
		}
	}
	for(i = 0; i < MAX; i++) //ѭ����ӡ����õ�����
        printf("%d  ", a[i]);
	return 0;
}
