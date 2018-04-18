/*
算法过程：

1.初始化顶点集合 S，一开始只将起点 v0 加入到 S 中。
2.初始化 mst 数组，初值均为 v0。
3.初始化 lowcost 数组，初值为 v0 到各顶点的距离，无边则为 INF。
4.重复以下步骤，直到所有顶点都在 S 中为止：
    1.将 lowcost 值最小的顶点 v 加入到 S 中。
    2.更新与顶点 v 相邻顶点的 mst 值。
    3.更新与顶点 v 相邻顶点的 lowcost 值。
 */

#include <iostream>
#include <cstdio>
#define INF 10000

using namespace std;

typedef char DATATYPE;


/* 功能：创建图的邻接矩阵
 * 参数：顶点序列、边序列、用于存放顶点个数和顶点数据的变量
 * 返回值：邻接矩阵（二级指针）
 */

/*
 *  S：生成树顶点集合，初始只含起点 v0。
 *  mst[i]：存放 S 中距离顶点 i 最近的顶点编号。
 *  lowcost[i]：存放 S 到顶点 i 的最短距离。
 */

int** CreateMGraph(char* vertex, char* edges, int &vNum, DATATYPE* &vData)
{
    char index[128]; //存放顶点字符对应的下标
    char* p = vertex;
    int count = 0;

    //计算顶点个数
    while (*p++ != '\0') count++;
    vNum = count;
    //初始化顶点数组
    vData = new DATATYPE[count+1];
    for (int i = 0; i < count; i++)
    {
        vData[i] = vertex[i];
    }
    vData[count] = '\0';
    //初始化顶点下标数组
    for (int i = 0; i < count; i++)
    {
        index[vertex[i]] = i;
    }
    //初始化邻接矩阵
    int** MGraph = new int*[count];
    for (int i = 0; i < count; i++)
    {
        MGraph[i] = new int[count];
        for (int j = 0; j < count; j++)
        {
            MGraph[i][j] = INF;
        }
    }
    //将权值传入顶点矩阵
    char* pEdge = edges;
    char u, v;
    int weight;
    int flag;
    while(true)
    {
        flag = sscanf(pEdge, "(%c,%c,%d)", &u, &v, &weight);
        //边序列读取完毕
        if(flag != 3) break;
        MGraph[index[u]][index[v]] = weight;
        MGraph[index[v]][index[u]] = weight;
        //找到下一条边的读取位置
        while (*pEdge++ != ')');
    }

    return MGraph;
}


/* 功能：求最小生成树
 * 参数：邻接矩阵、顶点数据、顶点个数
 */
void Prim(int** MGraph, DATATYPE* vData, int vNum)
{
    int* lowcost = new int[vNum];
    int* mst = new int[vNum];

    //初始化lowcost与mst数组
    for (int i = 0; i < vNum; i++)
    {
        lowcost[i] = MGraph[0][i];
        mst[i] = 0;
    }

    //寻找最小生成树
    int min;
    int minid;
    int totalWeight = 0;
    for(int i = 0; i < vNum - 1; i++)
    {
        //查找与顶点集S连接的代价最小的边
        min = INF;
        minid = -1;
        for (int j = 1; j < vNum; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                minid = j;
            }
        }
        //将找到的顶点加入到顶点集S中（此处为输出），并将代价设为0
        cout << vData[mst[minid]] << "-" << vData[minid] << " = " << min << endl;
        totalWeight += min;
        lowcost[minid] = 0;
        //更新lowcost与mst
        for (int j = 1; j < vNum; j++)
        {
            if (MGraph[minid][j] < lowcost[j])
            {
                lowcost[j] = MGraph[minid][j];
                mst[j] = minid;
            }
        }
    }

    cout << "Total Weight: " << totalWeight << endl;
}


int main()
{
    int** MGraph;
    int vNum = 0;
    DATATYPE* vData;

    char vertex[] = "ABCDEF";
    char edges[] = "(A,B,5)(A,F,2)(B,C,8)(B,E,4)(C,D,3)(C,E,7)(D,E,9)(E,F,6)";

    MGraph = CreateMGraph(vertex, edges, vNum, vData);

    Prim(MGraph, vData, vNum);

    return 0;
}