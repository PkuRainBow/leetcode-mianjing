
#include <iostream>
#include <vector>

using namepace std;

vector<int> LPI(vector<int>& array) {
	int start = 0, end = 0;
	int max_len = 0, max_start = 0;
	vector<int> result;
	int cur = 0;
	while (cur <　array.size()) {
		while (cur < array.size() && nums[cur] < 0) end++;
		if (cur == array.size()) break;
		start = cur;
		end = cur;
		while (end < array.size() && nums[end] > 0) end++;
		int cur_len = end - start;
		if (cur_len > max_len) {
			max_start = start;
			max_len = cur_len;
		}
	}
	for (int i = max_start; i < max_start + max_len; i++) {
		result.push_back(array[i]);
	}
	return result;
}

int main() {

	return 0;
}