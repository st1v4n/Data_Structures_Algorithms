/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

class Solution {
public:

    void mark(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0'){
            return;
        }
        grid[i][j]='0';
        mark(grid, i-1, j);
        mark(grid, i+1, j);
        mark(grid, i, j-1);
        mark(grid, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    mark(grid, i, j);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};
