#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void DFS(int i, int j, vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1'){
            return; 
        }
        grid[i][j] = '2';
        DFS(i, j - 1, grid);
        DFS(i, j + 1, grid);
        DFS(i - 1, j, grid);
        DFS(i + 1, j, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    DFS(i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    Solution s;
    int islands = s.numIslands(grid);
    cout << "The number of islands: " << islands;
}