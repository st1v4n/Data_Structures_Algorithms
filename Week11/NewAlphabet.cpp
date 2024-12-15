/*
You are given N: number of words
On the next N rows, You are given word[i] : a word with alphabetically correct sequence, depending on a specific new alphabet
return the correct sequence of the characters
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>
using namespace std;

stack<char> topological;
vector<bool> visited(256, 0);
bool letters[256]{false};
void dfs(char curr, unordered_map<char, unordered_set<char>>& graph, vector<bool>& visited){
    visited[curr] = true;
    for(auto &v:graph[curr]){
        if(!visited[v]){
            dfs(v, graph, visited);
        }
    }
    topological.push(curr);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);  
    int N;
    cin>>N;
    unordered_map<char, unordered_set<char>> graph;
    vector<string> words(N);
    for(int i=0;i<N;i++){
        cin>>words[i];
    }
    if(N==1){
        for(int i=1;i<words[0].size();i++){
            if(words[0][i] != words[0][i-1]){
                cout<<words[0][i-1]<<' ';
            }
        }
        if(words[0][words[0].size()-1] != words[0][words[0].size()-2]){
            cout<<words[0][words[0].size()-1];
        }
        return 0;
    }
    int end = N-1;
    for(int i=0;i<end;i++){
        int min_sz = std::min(words[i].size(), words[i+1].size());
        for(int j=0;j<min_sz;j++){
            if(words[i][j] == words[i+1][j]){
                continue;
            }
            graph[words[i][j]].insert(words[i+1][j]);
            letters[words[i][j]] = true;
            letters[words[i+1][j]] = true;
            break;
        }
    }
    for(char i = 'a'; i<= 'z'; ++i){
        
        if(letters[i] && !visited[i])dfs(i, graph, visited);
    }
    while(topological.size()){
        cout<<topological.top()<<' ';
        topological.pop();
    }
    return 0;
}
