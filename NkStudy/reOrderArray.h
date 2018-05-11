#pragma once
#include <vector>

void reOrderArray(std::vector<int> &array)
{
	if (array.empty()) {
		return;
	}

	std::vector<int> res;

	for (size_t i = 0; i < array.size(); ++i) {
		if ((array[i] & 1) != 0) {
			res.push_back(array[i]);
		}
	}

	for (size_t j = 0; j < array.size(); ++j) {
		if ((array[j] & 1) == 0) {
			res.push_back(array[j]);
		}
	}

	array = res;
}
