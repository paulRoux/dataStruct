/***************************
矩阵连乘 动态规划迭代实现
A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25
p[0-6]={30,35,15,5,10,20,25}
****************************/

#include <stdio.h>
#include <string.h>
#define NUM 7

int m[NUM][NUM];
int s[NUM][NUM];

int MatixChain(int n, int *p)
{
	for(int i = 0; i < n; ++i)
	{
		m[i][i] = 0;
	}
	for(int r = 2; r <= n; ++r) //最开始最少有两个矩阵r = 2,r小于最大的个数
	{
		for(int i = 1; i <= n-r+1; ++i) //判断没有进行操作的矩阵的个数
		{
			int j = i + r -1;  //分割点的位置
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for(int k = i+1; k < j; ++k)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if(t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][NUM - 1];
}

void TraceBack(int i, int j)
{
	if(i == j)
	{
		printf("A%d", i);
	}
	else
	{
		printf("(");
		TraceBack(i, s[i][j]);
		TraceBack(s[i][j] + 1, j);
		printf(")");
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int p[NUM] = {35, 30, 15, 5, 10, 20, 25};
	printf("min = %d\n", MatixChain(n, p));
	TraceBack(1, n);
	putchar(10);
	return 0;
}