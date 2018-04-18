#include <iostream>
using namespace std;

#define MAX 4

void Swap();
void PermSort();
int confirm();

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Confirm(int a[], int k, int i)
{
    if(i > k)
        for(int t = k; t < i; t++)
            if(a[t] == a[i])
                return 0;
    return 1;
}

void PermSort(int a[], int k, int m)
{
	if(k == m)
	{
		for(int i = 0; i <= m; ++i)
			cout<<a[i];
		cout<<endl;
	}
	else
	{
		for(int i = k; i <= m; ++i)
		{
			if(Confirm(a, k, i))
			{
				Swap(a[k], a[i]);
				PermSort(a, k+1, m);
				Swap(a[k], a[i]);
			}
		}
	}
}

int main()
{
	int a[MAX] = {3, 1, 2, 3};
	PermSort(a, 0, MAX-1);
	return 0;
}