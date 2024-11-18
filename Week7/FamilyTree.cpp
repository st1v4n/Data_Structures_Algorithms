/*
You are given a tree
After that, you are given Q queries
each query consists of two peaks of the tree
return (The faster possible way) if the left side of the query is parent of the right side of the query
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
uint32_t timer = 0;
pair<int, int> times[1000001];
int N, Q;
struct TreeNode {
    int val = 0;
    vector<TreeNode*> p;
    TreeNode() = default;
    TreeNode(int val) :val(val) {}
    TreeNode(int val, const vector<TreeNode*>& p) : val(val), p(p) {}
};
void print(TreeNode* root) {
    if (!root)return;
    times[root->val].first = timer++;
    for (int i = 0;i < root->p.size();i++) {
        print(root->p[i]);
    }
    times[root->val].second = timer++;
}

bool isSubInterval(int& L, int& R, int& l1, int& r1) {
    return (l1 >= L && r1 <= R);
}

void generateTree(vector<TreeNode*>& nodes) {
    int a, b;
    int end = N - 1;
    int iter = 0;
    for (int i = 0;i < end;i++) {
        cin >> a >> b;
        if (!nodes.size()) {
            nodes.push_back(new TreeNode(a));
            nodes[iter]->p.push_back(new TreeNode(b));
            continue;
        }
        if (a == nodes[iter]->val) {
            nodes[iter]->p.push_back(new TreeNode(b));
        }
        else {
            for (int j = 0;j < nodes[iter]->p.size();j++) {
                nodes.push_back(nodes[iter]->p[j]);
            }
            for (int j = iter; j < nodes.size();j++) {
                if (nodes[j]->val == a) {
                    iter = j;
                    break;
                }
            }
            nodes[iter]->p.push_back(new TreeNode(b));
        }
    }
}

int main() {
    cin >> N;
    vector<TreeNode*> nodes;
    generateTree(nodes);
    print(nodes[0]);
    cin >> Q;
    vector<bool> counts(Q);
    for (int i = 0;i < Q;i++) {
        int a, b;
        cin >> a >> b;
        counts[i] = isSubInterval(times[a].first, times[a].second, times[b].first, times[b].second);
    }
    for (int i = 0;i < Q;i++) {
        if (counts[i]) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}
