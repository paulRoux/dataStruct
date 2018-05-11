#pragma once
#include <iostream>

int jumpFloor(int number)
{
	int res[2] = { 0, 1 };
	if (number < 2) {
		return res[number];
	}

	int sum = 0;
	int num1 = 0;
	int num2 = 1;
	for (int i = 1; i <= number; ++i) {
		sum = num1 + num2;
		num1 = num2;
		num2 = sum;
	}

	return sum;
}