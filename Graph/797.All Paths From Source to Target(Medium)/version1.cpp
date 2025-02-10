#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    private:
        vector<int> path;  // 儲存單一路徑
        vector<vector<int>> result;
        void dfs(vector<vector<int>>& graph,int x){
            // 終止條件: x 已遍歷到結尾
            if(x == graph.size()-1){
                result.push_back(path);  // 將路徑加到 result
            }
            else{
                // 針對 x 點的所有射出點
                for(int i = 0;i < graph[x].size();i++){
                    path.push_back(graph[x][i]);  // 將 graph[x][i] 點加進路徑
                    dfs(graph,graph[x][i]);       // 從 graph[x][i] 開始再遞迴做 dfs，不斷加點進去
                    path.pop_back();  // 撤銷該點
                }
            }  
        }
    public: 
        
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            path.push_back(0);  // 路徑永遠是從 0 開始
            dfs(graph,0);
            return result;
        }
    };

int main() {
    vector<vector<int>> graph = {{1,2},{3},{3},{}};

    Solution s;
    vector<vector<int>> result = s.allPathsSourceTarget(graph);
    for(int i = 0;i < result.size();i++){
        for(int j = 0;j < result[i].size();j++){
            cout<<result[i][j]<<",";
        }
        cout<<endl;
    }
}