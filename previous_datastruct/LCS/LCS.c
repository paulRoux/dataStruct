#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 20
int c[NUM][NUM];  //保存最长公共子序列的长度
int b[NUM][NUM];  //保存c[i][j]是由那一个子问题解决的

void LCSLength(int m, int n, char x[], char y[])
{
	int i = 0,
		j = 0;

	//初始化0行0列为0
	for(i = 0; i < m; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			c[i][j] = 0;
		}
	}
	for(i = 1; i <= m; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			if(x[i-1] == y[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1;  //指向左上角的箭头
			}
			else if(c[i-1][j] > c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 2;  //指向上面的箭头
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 3;  //指向左边的箭头
			}
		}
	}
}

void LCS(int i, int j, char x[])
{
	if(0 == i || 0 == j)
		return;
	if(b[i][j] == 1)
	{
		LCS(i-1, j-1, x);
		printf("%c ", x[i]);
	}
	else if(b[i][j] == 2)
	{
		LCS(i-1, j, x);
	}
	else
	{
		LCS(i, j-1, x);
	}
}

int main()
{
	char x[NUM];
	char y[NUM];
	strcpy(x, " ABCBDAB");  //需要加一个空格,否则少匹配第一个字符
    strcpy(y, " BDCABA");

	int x_len = strlen(x);
	int y_len = strlen(y);

	LCSLength(x_len, y_len, x, y);
	printf("%d\n", c[x_len-1][y_len-1]);
	LCS(x_len, y_len, x);
	putchar(10);

	return 0;
}