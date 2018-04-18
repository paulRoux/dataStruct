#include <iostream>
using namespace std;

#define MAX 10

int main()
{
	int i, j, temp;
	int a[MAX] = {1, 3, 65, 32, 33, 5, 23, 32, 34, 62};
	for (int i = 0; i < MAX; ++i)
	{
		/* code */
		for (int j = i+1; j < MAX; ++j)
		{
			/* code */
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		cout<<a[i]<<endl;
	}
	return 0;
}