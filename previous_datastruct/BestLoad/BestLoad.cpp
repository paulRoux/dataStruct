#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;


struct load
{
	int index;
	int w;
}box[1001];

bool cmp(load a, load b)
{
	if(a.w < b.w)
		return true;
	else
		return false;
}

int main()
{
	int c, n;

	while(scanf("%d%d", &c, &n) != EOF)
	{
		load box[1001] = {0};  //初始化
		int x[1001] = {0};

		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &box[i].w);
			box[i].index = i;
		}

		sort(box, box+n+1, cmp);

		if(box[1].w > c)
		{
			printf("No Anwser!\n");
			continue;
		}

		int i;
		for(i = 1; i <= n && box[i].w <= c; ++i)
		{
			x[box[i].index] = 1;
			c -= box[i].w;
		}

		printf("numbers:%d\n", i-1);
		printf("index:");

		for(i = 1; i <= n; ++i)
		{
			if(x[i])
				printf("%d ", i);
		}

		printf("\n");
	}
	return 0;
}