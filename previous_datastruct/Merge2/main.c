#include <stdio.h>
#include <stdlib.h>

#define N 10
int MergeSort(int a[], int n);
int Merge(int a[], int n);
int main()
{
	/* code */
	int i;
	int a[N] = {12, 4, 45, 13, 5, 75, 32, 3, 8, 32};
	MergeSort(a, N);
	for(i = 0; i < N; i++)
		printf("%d  ", a[i]);
	return 0;
}

int MergeSort(int a[], int n)
{
	if(n <= 1)
		return 1;
	MergeSort(a, n/2);
	MergeSort(a+n/2, n-n/2);
	Merge(a, n);
	return 1;
}


int Merge(int a[], int n)
{
	int s1, s2, mid, i = 0, k = 0;
	int b[n];
	mid = n/2, s1 = 0, s2 = mid;
	while(s1<mid && s2 < n)
	{
		if(a[s1] <= a[s2])
            b[k++] = a[s1++];
        else
            b[k++] = a[s2++];
	}
	if(s1 < mid)
		for(i = s1; i < mid; i++)
		{
			b[k++] = a[i];
		}
	else
		for(i = s2; i < n; i++)
		{
			b[k++] = a[i];
		}
    for(k = 0; k < n; k++)
    {
        a[k] = b[k];
    }
    return 1;
}
