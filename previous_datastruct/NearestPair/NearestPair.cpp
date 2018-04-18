#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

/*
   核心是分治算法

1. 分别根据点的 x,y 值进行排序

2. 在 x 轴上划一道垂线, 将点均分成两半

3. 假设最近点对都在左/右部分, 递归计算左/右半部分的最短距离
   并返回较小值 dis

4. 假设最近点对分别在左右两个部分, 横跨中心的竖线. 中心线为中心,
   2*dis 为宽度画一个矩形, 横跨中心线的最近点对 candidate 都在这个矩形内.
   将这些点按照 y 值的大小加入到数组中. 遍历数组中的点, 将该点与其后的
   7 个点计算距离, 返回最小距离

5. 为什么仅和 7 个点作对比呢. 因为已经假设 dis 是左右不分最近点对的最小值,
   这就说明在一个长(宽)为 dis 的正方形内, 至多有 4 个点. 长为 dis*2,
   宽为 dis 的长方形至多 8 个.
*/

const double INF = 1e20;  //10^20，科学计数方法
#define N 100010

struct Point
{
    double x;
    double y;
}point[N];  //point用来存储输入的坐标点

int n;
int tmpt[N];  //tmpt[]用来保存，中间区域点的顺序


int cmpxy(const void *a, const void *b) //对所有的点进行横坐标升序排序
{                                       //横坐标相同的按纵坐标升序
    Point *c=(Point *)a;
    Point *d=(Point *)b;
    if(c->x!= d->x)
        return c->x-d->x;
    return c->y-d->y;
}

int cmpy(const void *a, const void * b) //中间区域排序
{
    //对距离mid点横向距离少于d的点，进行纵坐标升序排序
    int c=*(int*)a, d=*(int*)b;
    return point[c].y - point[d].y;
}

double min(double a, double b)
{
    return a < b ? a : b;
}

double dis(int i, int j)  //计算两点间的距离
{
    return sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+
                (point[i].y-point[j].y)*(point[i].y-point[j].y));
}

double Closest_Pair(int left, int right)  //求解最近点对
{
    double d = INF;
    if(left==right)   //二分到区间只有一个点时，返回
        return d;
    if(left + 1 == right)  //二分到区间只有两个点时，返回两点间的距离
        return dis(left, right);
    int mid = (left+right)/2;  //取中间位置
    double d1 = Closest_Pair(left,mid);  //求左边最小距离
    double d2 = Closest_Pair(mid+1,right);  //求右边最小距离
    d = min(d1,d2);
    int i,j,k=0;

    //分离出距离中心横向宽度为d的点区间
    for(i=left;i<=right;i++)
    {
        if(fabs(point[mid].x-point[i].x)<=d)
            tmpt[k++]=i;
    }
    qsort(tmpt,k,sizeof(int),cmpy);  //分离出来的区间点，纵坐标进升序排序

    //线性扫描，求解中间位置两侧的最小两点距离
    for(i = 0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(point[tmpt[j]].y-point[tmpt[i]].y<d)
            {
               double d3 = dis(tmpt[i],tmpt[j]);
               if(d > d3)
               d = d3;
            }
        }
    }
    return d;

}


int main()
{
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%lf%lf",&point[i].x,&point[i].y);

        qsort(point,n,sizeof(Point),cmpxy);

        printf("%.4lf\n",Closest_Pair(0,n-1));

        return 0;
}
