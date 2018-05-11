// nkStudy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "reOrderArray.h"


int main()
{
	std::vector<int> arr = { 1, 2, 8, 9 ,4, 7, 10, 13};

	reOrderArray(arr);
	return 0;
}

