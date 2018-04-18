#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 5

int Partation(int a[])
{
    return rand()%MAX;
}

int Search(int a[], int n, int k)
{
    int i = 0;
    if(k >= n)
        return -1;
    else
    {
         i = Partation(a);
         if(i == k)
             return i;
         else if(i > k)
             return Search(a, i, k);
         else
             return Search(a + i + 1, n - i - 1, k - i - 1);
    }
}

int main()
{
    int a[MAX] = {2, 4, 54, 21, 44};
    int k = 0,
        num = 0,
        len = 0;
    printf("请输入想要查询的数的位置：");
    scanf("%d", &k);
    len = sizeof(a);
    num = Search(a, len, k);
    printf("%d", a[num]);
    return 0;
}
