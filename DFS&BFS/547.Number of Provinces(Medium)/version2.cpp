#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void BFS(vector<vector<int>>& isConnected,vector<int> &visited,int v){
        int n = isConnected.size();     
        queue<int> q;
        q.push(v);
        // 持續拜訪直到 queue 為空
        while(!q.empty()){
            int i = q.front();
            q.pop();
            // 對於相鄰於點 i 且上未被拜訪的點 j
            for(int j = 0;j < n;j++){
                if(isConnected[i][j] == 1 && visited[j] != 1){
                    visited[j] = 1;  // 拜訪 j
                    q.push(j);       // 將 j 加入 queue 中
                }
            }
        }
    }
    // 用 BFS 解
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<int> visited(n,0);
        for(int i = 0;i < n;i++){
            if(visited[i] != 1){
                BFS(isConnected,visited,i);
                provinces++;
            }
        }
        return provinces;
    }
};

int main() {
    vector<vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};

    Solution s;
    int provices = s.findCircleNum(isConnected);
    cout<<"The number of provinces: "<<provices;
}