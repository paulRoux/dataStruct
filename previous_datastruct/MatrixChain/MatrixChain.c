/***************************
重叠子问题的递归最优解
A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25
p[0-6]={30,35,15,5,10,20,25}
****************************/

#include <stdlib.h>
#include <stdio.h>
#define  L  7

int RecurMatrixChain(int i,int j,int **s,int *p)//递归求最优解
{
	if(i == j)
		return 0;
	int u = RecurMatrixChain(i,i,s,p)+RecurMatrixChain(i+1,j,s,p)+p[i-1]*p[i]*p[j];
	s[i][j] = i;

	for(int k=i+1; k < j; k++)
	{
		int t = RecurMatrixChain(i,k,s,p) + RecurMatrixChain(k+1,j,s,p) + p[i-1]*p[k]*p[j];
		if(t < u)
		{
			u = t;
			s[i][j] = k;
		}
	}
	return u;
}

void Traceback(int i,int j,int **s)//构造最优解
{
	if(i==j)
		return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	printf("Multiply A%d,%d", i, s[i][j]);
	printf(" and A%d,%d\n", s[i][j]+1, j);
}

int main()
{
	int p[L]={30,35,15,5,10,20,25};

    int **s = (int **)malloc(sizeof(int*)*L);
	for(int i=0;i<L;i++)
    {
		s[i] = (int*)malloc(sizeof(int)*L);
    }

	printf("min:%d\n", RecurMatrixChain(1,6,s,p));
	printf("Best Result:\n");
	Traceback(1,6,s);
	return 0;
}