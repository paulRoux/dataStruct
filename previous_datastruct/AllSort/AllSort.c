#include <stdio.h>
#include <stdlib.h>
#define M 10

void ReSort(int a[], int b[], int n)
{
    int i = 0, j = 0;
    while(i < n){
        j = a[i];
        b[j]+=1;
        i++;
    }
}

int main()
{
    int a[M] = {2, 3, 3, 3, 5, 6, 6, 7, 5, 1};
    int b[M] = {0};
    int i , temp = 0, x;
    ReSort(a, b, M);
    for(i = 0; i < M; i++)
    {
        if(b[temp] < b[i+1]){
            temp = b[i+1];
            x = i;
        }
    }
    printf("%d %d", x, temp);
    return 0;
}
