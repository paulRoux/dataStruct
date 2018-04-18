#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

void QuickSort(int a[], int low, int high);
int Partation(int a[], int low, int high);
void swap(int *a, int *b);

int NearestPair(int a[], int n)
{
    int dr, min, dl;
    if(n <= 1)
        return INF;
    else
    {
        dl = NearestPair(a, n/2);
        dr = NearestPair(a + n/2, n - n/2);
        min = dl < dr ? dl : dr;
        if(min > a[n/2] - a[n/2 - 1])
            min = a[n/2] - a[n/2 - 1];
        return min;
    }
}

void QuickSort(int a[], int low, int high)
{
     int  p = 0;
     if(low < high)
     {
         p = Partation(a, low, high);
         QuickSort(a, low, p - 1);
         QuickSort(a, p + 1, high);
     }
}

int Partation(int a[], int low, int high)
{
     int tmp = a[high],
        i = low - 1,
        j = low;
     for(; low < high - 1; ++low)
     {
          if(a[j] < tmp)
          {
              swap(&a[i + 1], &a[j]);
              i++;
          }
     }
     swap(&a[high], &a[i + 1]);
     return i + 1;
}

void swap(int *a, int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}

int main()
{
    int a[5] = {20, 4, 11, 32, 21};
    int len = sizeof(a)/sizeof(int),
        x = 0;
    QuickSort(a, 0, len - 1);
    for(int i = 0; i < len; ++i)
    printf("%d ", a[i]);
    x = NearestPair(a, len);
    printf("%d", x);
    return 0;
}
