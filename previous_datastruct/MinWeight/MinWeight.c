#include <stdio.h>

int num;  //零件个数
int Merchant;  //商家个数
int MaxPrice;  //最大价格
int price;  //当前价格
int weight;  //当前重量
int MinWeight;  //最小重量
int Weight[100][100];  //重量,二维数组一行代表一个商家
int Price[100][100];  //价格,二维数组一行代表一个商家
int temp[100];  //临时数组保存零件来源商家
int best[100];  //保存零件的最佳来源商家

void dfs(int t)
{
	if(t == num)  //判断是否到叶子节点
	{
		if(price <= MaxPrice && weight < MinWeight)  //判断总价格是否小于最大价格并且判断此时的重量小于当前最小重量
		{
			MinWeight = weight;  //保存此时的重量为最小重量
			for(int i = 0; i < num; ++i)
				best[i] = temp[i] ;  //此时的零件来源保存为最佳来源数组
		}
		return;
	}

	for(int i = 0; i < Merchant; ++i)  //循环商家，向下一个节点查找
	{
		weight += Weight[t][i];  //更新重量
		price += Price[t][i];  //更新价格
		temp[t] = i;  //保存当前的零件来源商家

		if(price <= MaxPrice && weight < MinWeight)  //此时重量小于最小重量，并且满足价格小于最大价格继续判断下个零件
			dfs(t+1);

		weight -= Weight[t][i];  //向上回溯更新重量
		price -= Price[t][i];  //向上回溯更新价格
		temp[t] = 0;  //到根节点更新零件来源商家
	}
}

int main()
{
	scanf("%d %d %d", &num, &Merchant, &MaxPrice);  //接收三个参数为零件个数，商家，最大总价格

	for(int i = 0; i < num; ++i)  //先存零件的价格
	{
		for(int j = 0; j < Merchant; ++j)
		{
			scanf("%d", &Price[i][j]);
		}
	}

	for(int i = 0; i < num; ++i)  //然后存零件的重量
	{
		for(int j = 0; j < Merchant; ++j)
		{
			scanf("%d", &Weight[i][j]);
		}
	}

	price = 0;  //当前价格初始为0
	MinWeight = 65535;  //最小重量初始为65535
	weight = 0;  //当前重量初始为0
	dfs(0);  //深度优先搜索找到最优解,从根节点开始

	printf("The MinWeight is: %d\n", MinWeight);  //打印最小重量
	printf("The Merchant is: ");

	for(int i = 0; i < num; ++i)
	{
		printf("%d ", best[i]+1);  //打印相关厂商
	}
	printf("\n");
	return 0;
}