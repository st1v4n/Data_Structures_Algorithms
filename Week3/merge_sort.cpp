/*
merge sort algorithm
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, vector<int>& buff) {
	int firstIndex = left;
	int secondIndex = mid;
	int iter = 0;

	while (firstIndex < mid && secondIndex < right) {
		if (arr[firstIndex] <= arr[secondIndex]) {
			buff[iter++] = arr[firstIndex++];
		}
		else {
			buff[iter++] = arr[secondIndex++];
		}
	}

	while (firstIndex < mid) {
		buff[iter++] = arr[firstIndex++];
	}
	while (secondIndex < right) {
		buff[iter++] = arr[secondIndex++];
	}

	for (int i = 0;i < iter;i++) {
		arr[left + i] = buff[i];
	}
}

void split(vector<int>& arr, int leftIndex, int rightIndex, vector<int>& buff) {
	if (rightIndex - leftIndex < 2) {
		return;
	}
	int mid = leftIndex + (rightIndex - leftIndex) / 2;
	split(arr, leftIndex, mid, buff);
	split(arr, mid, rightIndex, buff);
	merge(arr, leftIndex, mid, rightIndex, buff);
}

void merge_sort(vector<int>& arr) {
	if (arr.size() <= 1) {
		return;
	}
	vector<int> buff(arr.size());
	split(arr, 0, arr.size(), buff);
	for (int i = 0;i < arr.size();i++) {
		std::cout << arr[i] << ' ';
	}
}

int main() {
	vector<int> arr = { 7, 1, 3, 8, 9, 10, 0, 11, -2, -3, 5 };
	merge_sort(arr);
}
