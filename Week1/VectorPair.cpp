#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using std::vector;
using std::pair;
static int solution()
{
    int n, k;
    std::cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0;i < n;i++) {
        std::cin >> v[i].first;
        v[i].second = i;
    }
    std::sort(v.begin(), v.end());
    int begIndex = 0;
    int endIndex = v.size() - 1;
    while (begIndex != endIndex) {
        if (v[begIndex].first + v[endIndex].first == k) {
            std::cout << v[begIndex].second << " " << v[endIndex].second;
            return 0;
        }
        else if (v[begIndex].first + v[endIndex].first < k) {
            begIndex++;
        }
        else {
            endIndex--;
        }
    }
    return 0;
}


