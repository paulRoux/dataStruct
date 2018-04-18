#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum = 0;
void SubsetSum(int *S, int *best, int n, int MAX, int start)
{
	if(start == n)
	{
		if(sum == MAX)
		{
			printf("The result is: ");
			for(int i = 0; i < n; ++i)
			{
				if(best[i])
				{
					printf("%d ", S[i]);
				}
			}
			putchar(10);
		}
		return;
	}

	/*将这个数加上*/
	sum += S[start];
	best[start] = 1;
	if(sum <= MAX)
		SubsetSum(S, best, n, MAX, start+1);

	/*将数据还原，进行回溯*/
	best[start] = 0;
	sum -= S[start];
	SubsetSum(S, best, n, MAX, start+1);
}

int main()
{
	int n = 0,
		MAX = 0;
	scanf("%d%d", &n, &MAX);
	int *S = (int *)malloc(sizeof(int) * n);
	int *best = (int *)malloc(sizeof(int) * n * n);
	memset(best, 0, sizeof(best));

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &S[i]);
	}

	SubsetSum(S, best, n, MAX, 0);

	int flag = 0;
	for(int i = 0; i < n; ++i)
	{
		if(best[i++] == 0)
			flag = 1;
	}
	if(flag == 1)
		printf("No Solution!\n");
	free(S);
	free(best);
	return 0;
}