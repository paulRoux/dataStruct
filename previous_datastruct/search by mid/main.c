#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int main()
{
	int low = 0, high, mid, x;
	int a[MAX] = {1, 2, 5, 7, 8, 11, 14, 20};
	high = MAX-1;
	printf("请输入想要搜索的数据:");
	scanf("%d", &x);
	while(low <= high)
    {
        mid = (low+high)/2;
        if(a[mid] > x)
			high = mid-1;
		else if(a[mid] < x)
			low = mid+1;
        else
            printf("%d", mid);
        if(a[mid] == x)
            break;
	}
	return 0;
}
