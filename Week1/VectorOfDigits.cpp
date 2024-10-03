#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using std::vector;
using std::pair;
static int solution() {
	int n;
	std::cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		std::cin >> v[i];
	}
	int end = v.size() - 1;
	v[end]++;
	for (int i = end;i > 0;i--) {
		if (v[i] > 9) {
			v[i] = 0;
			v[i - 1]++;
		}
		else {
			break;
		}
	}
	if (v[0] == 10) {
		v[0] = 0;
		auto beg = v.begin();
		v.insert(beg, 1);
	}
	end = v.size();
	for (int i = 0; i < end; i++) {
		std::cout << v[i] << " ";
	}
	return 0;
}