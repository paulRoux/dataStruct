#include <iostream>
#include <algorithm>
using namespace std;

//方便管理定义结构体
struct data
{
    int start,  //起始时间
    	end;  //结束时间
}a[100001];

int cmp(const data &a, const data &b)
{
    if(a.end < b.end)  //对结束时间进行比较
    	return 1;
    else
    	return 0;
}

int main()
{
    int i = 0, n = 0;
    cout<<"How many groups are you want to arragement:";
    cin>>n;

    while(i < n)
    {
    	cin>>a[i].start>>a[i].end;
        if(a[i].start == 0 && a[i].end == 0)
        {
        	break;
        }
        i++;
	}

    sort(a, a+i, cmp);

    int end=0,
    	ans=0;

    for(int j=0; j <= i; j++)  //贪的是结束的时间最早
    {
       if(a[j].start >= end)
       {
			end = a[j].end;
			ans++;
		}
	}

    cout<<"The best measure is:"<<ans<<endl;
    return 0;
}