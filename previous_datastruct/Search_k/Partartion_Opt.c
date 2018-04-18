#include <stdio.h>
#include <string.h>
#define MAX 5

void BubbleSort(int a[], int len)
{
    int i = 0,
        j = 0,
        temp = 0;
    for(i = 0; i < len; ++i)
        for(j = i + 1; j < len; ++j)
        {
            if(a[i] > a[j])
            {
                 temp = a[i];
                 a[i] = a[j];
                 a[j] = temp;
            }
        }
}

int Partation_Opt(int a[], int n)
{
    int low,
        high,
        x,
        p,
        i,
        v;
    if(n < 25)
    {
         BubbleSort(a, n);
         return n/2;
    }
    else
    {
         for(i = 0; i < n/5; ++i)
         {
             BubbleSort(a + i * 5, 5);
             v = a[i * 5 + 2];
             a[i + 5 + 2] = a[i];
             a[i] = v;
         }
         //x = Search(a, n/5, n/10);
         p = a[x];
         a[x] = a[0];
         x = 0;
         low = 0;
         high = n - 1;
         while(low < high)
         {
              while(low < high && a[high] > p)
                  high--;
              if(low < high)
              {
                   a[x] = a[high];
                   x = high;
              }
              while(low < high && a[low] <= p)
                  low++;
              if(low < high)
              {
                   a[x] = a[low];
                   x = low;
              }
         }
         a[x] = p;
         return x;
    }
}

int main()
{
    int a[MAX] = {2, 34, 4, 23, 3};
    int x,
        len = 0;
    len = sizeof(a)/sizeof(int);
    x = Partation_Opt(a, len);
    return 0;
}
