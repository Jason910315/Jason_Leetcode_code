#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void DFSUtil(vector<vector<int>>& isConnected, vector<int> &visited, int v){
        int n = isConnected.size();
        for(int i = 0;i < n;i++){
            // 若點 i 與 v 相鄰且 i 尚未被拜訪，則繼續對其做 DFS
            if(isConnected[v][i] == 1 && visited[i] != 1){
                visited[i] = 1;  // i 設為被拜訪
                DFSUtil(isConnected,visited,i);
            }
        }
    }
    // 用 DFS 解
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;  
        // visited 儲存頂點拜訪與否，0 表示尚未拜訪
        vector<int> visited(n,0);
        // 針對每個頂點判斷若其尚未拜訪則對該點做 DFS
        for(int i = 0;i < n;i++){
            if(visited[i] != 1){
                DFSUtil(isConnected,visited,i); // DFS 只會追蹤所有與頂點直接或間接相鄰的點
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