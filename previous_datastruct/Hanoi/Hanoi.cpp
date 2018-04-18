#include <iostream>

using namespace std;

void move(int n, char x, char y)
{
    cout<<"No."<<n<<": "<<x<<" -> "<<y<<endl;
}

void hanoi(int n, char a, char b, char c)
{
    if(n == 1)
        move(1,a,c);
    else
    {
        hanoi(n-1,a,c,b);  //可以理解为通过借助c，在b处已经放好n-1个盘
        move(n,a,c);       //第n号盘从a处移到c
        hanoi(n-1,b,a,c);  //解决b处n-1个盘，最后放到c处
 	}
}

int main()
{
    cout<<"The process for Hannoi:"<<endl;
    int num = 4;  //初始化为1
    hanoi(num,'A','B','C');
    cout<<"The process is finished!"<<endl;
    return 0;
}