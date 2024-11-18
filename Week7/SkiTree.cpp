/*
Given A tree, print the sum of each vertical in it
example
               1
              / \
             3   9
            / \ / \
           7  5 4  2
Output: 7 3 10 9 2
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val, Node* left = nullptr, Node* right = nullptr) :val(val), left(left), right(right) {}
};
int N;

void dfs(Node* root, int currPos, vector<uint64_t>& counts) {
    if (!root)return;
    dfs(root->left, currPos - 1, counts);
    counts[currPos] += root->val;
    dfs(root->right, currPos + 1, counts);
}

Node* generateTree(int N) {
    int a, b, c;
    vector<Node*> nodes(N);
    vector<pair<int, int>> pairs(N);
    for (int i = 0;i < N;i++) {
        cin >> a >> b >> c;
        nodes[i] = new Node(a);
        pairs[i].first = b;
        pairs[i].second = c;
    }
    for (int i = 0;i < N;i++) {
        if (pairs[i].first != -1) {
            nodes[i]->left = nodes[pairs[i].first];
        }
        if (pairs[i].second != -1) {
            nodes[i]->right = nodes[pairs[i].second];
        }
    }
    return nodes[0];
}

int countLeft(Node* root) {
    if (!root)return 0;
    return 1 + countLeft(root->left);
}
int countRight(Node* root) {
    if (!root)return 0;
    return 1 + countRight(root->right);
}
int main() {
    cin >> N;
    Node* root = generateTree(N);
    int size = countLeft(root);
    int sizeR = countRight(root->right);
    vector<uint64_t> counts(size + sizeR, 0);
    dfs(root, size - 1, counts);
    for (int i = 0;i < counts.size();i++) {
        cout << counts[i] << ' ';
    }
}
