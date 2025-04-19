#include <iostream>
#include <vector>

template <class T>
void insertionSort(std::vector<T>& array) {
	int n = array.size();
	for (int i = 1;i < n;++i) {
		T current = array[i];
		int backwardIter = i - 1;
		while (backwardIter >= 0 && current < array[backwardIter]) {
			array[backwardIter + 1] = array[backwardIter];
			backwardIter--;
		}
		array[backwardIter + 1] = current;
	}
}

int main() {
	std::vector<char> v = { 'b', 'd', 'a', 'z', 't', 'n' };
	insertionSort(v);
	for (int i = 0;i < v.size();++i) {
		std::cout << v[i] << '\n';
	}
	return 0;
}
