#pragma once
#include <vector>

bool Find(int target, std::vector<std::vector<int> > array)
{
	if (array.empty()) {
		return false;
	}

	long j = array[0].size()-1;
	long i = 0;
	while (i < array.size() && j >= 0) {
		if (array[i][j] > target) {
			--j;
		}
		else if (array[i][j] < target) {
			++i;
		}
		else {
			return true;
		}
	}

	return false;
}