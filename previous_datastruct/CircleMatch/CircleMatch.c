#include <stdio.h>
#include <string.h>
#include <math.h>

void CircleMath(int M)
{
    int N;   //N代表所有参加的运动员人数
    N = 1 << M;   //N = 2^M   计算所有的运动员人数
    int a[N + 1][N + 1];   //定义动态数组，从1开始所以需要N+1

    for(int i = 1; i <= N; ++i)   //对第一层进行初始化
        a[1][i] = i;

    for(int m = 1,tm = m, s = 1; s <= M; ++s)  //定义临时变量temp,控制循环变量 m 及 s
    {
        tm = m;
        m <<= 1;
        for(int t = 1;t <= N/m; ++t)
            for(int i = tm + 1; i <= m; ++i)
                for(int j = tm + 1; j <= m; ++j)
                {
                    a[i][j + m*(t - 1)] = a[i - tm][j + m*(t - 1) - tm];
                    a[i][j + m*(t - 1) - tm] = a[i - tm][j + m*(t - 1)];
                }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            printf("%3d", a[i][j]);
        puts("");
    }
}

int main()
{
    int M = 0;
    printf("请输入需要比赛的组数（2^M）：");
    scanf("%d", &M);
    CircleMath(M);
    return 0;
}
