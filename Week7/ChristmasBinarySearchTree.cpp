/*
Given T trees, return which of them are binary Search trees
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val, Node* left = nullptr, Node* right = nullptr) :val(val), left(left), right(right) {}
    ~Node() {
        delete left;
        delete right;
    }
};

bool isBSTUtil(Node* node, int min, int max) {
    if (node == nullptr) return true;

    if (node->val < min || node->val > max) return false;

    return isBSTUtil(node->left, min, node->val - 1) &&
        isBSTUtil(node->right, node->val + 1, max);
}


bool isBST(Node* root) {
    return isBSTUtil(root, INT32_MIN, INT32_MAX);
}
Node* generateTree(int N) {
    vector<Node*> nodes(N);
    vector<pair<int, int>> pairs(N);
    int a, b, c;
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


int main() {
    int T, N;
    cin >> T;
    vector<bool> trees(T);
    for (int i = 0;i < T;i++) {
        cin >> N;
        Node* currRoot = generateTree(N);
        trees[i] = isBST(currRoot);
        delete currRoot;
    }
    for (int i = 0;i < T;i++) {
        cout << trees[i] << endl;
    }
}