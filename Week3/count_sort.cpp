/*
count sort algorithm
*/

#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_NUMBER = 1e5;

void count_sort(vector<int>& arr) {
	int counts[MAX_NUMBER]{0};
	int max_number = arr[0];
	for (int i = 0;i < arr.size();i++) {
		counts[arr[i]]++;
		if (arr[i] > max_number) {
			max_number = arr[i];
		}
	}
	int iter = 0;
	for (int i = 0;i <= max_number;++i) {
		for (int j = 0;j < counts[i];j++) {
			arr[iter++] = i;
		}
	}

	for (int i = 0;i < arr.size();i++) {
		cout << arr[i] << ' ';
	}
}

int main() {
	vector<int> arr = { 7, 1, 3, 8, 9, 10, 0, 11, 2, 5, 13 };
	count_sort(arr);
}
