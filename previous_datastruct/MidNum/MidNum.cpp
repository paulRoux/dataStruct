#include <iostream>
using namespace std;

int a[100] = {0};

int MidSort(int n)
{
	if(a[n] > 0)
		return a[n];
	else
	{
		a[n] = 1;
		for (int i = 1; i <= n/2; ++i)
		/* code */
			a[n]+=MidSort(i);
		return a[n];
	}

}

int main()
{
	/* code */
	int n, sum = 0;
	while(cin>>n)
	{
		sum = MidSort(n);
		cout<<"sum:"<<sum<<endl;
	}
	return 0;
}
