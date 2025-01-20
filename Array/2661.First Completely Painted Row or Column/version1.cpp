#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();     // 取出mat有幾行
        int m = mat[0].size();  // 取出mat每一行有幾個元素(有幾列)
        unordered_map<int,pair<int,int>> mp; // mp儲存mat元素值及其對應的行列值
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        vector<int> cntRow(n,0);  // 紀錄一行是否被填滿
        vector<int> cntCol(m,0);  // 紀錄一列是否被填滿
        for(int i = 0;i < arr.size();i++){
            // v變數儲存arr[i]元素(對應到mat陣列裡的元素)的行列值
            auto& v = mp[arr[i]];
            cntRow[v.first]++;  // v.first代表其在第幾行
            if(cntRow[v.first] == m){ // 某一行已被填滿(已存在m個元素，某行飽和)
                return i;
            }
            cntCol[v.second]++; // v.second代表其在第幾列
            if(cntCol[v.second] == n){ // 某一列已被填滿(已存在n個元素，某列飽和)
                return i;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mat = {{3,2,5},{1,4,6},{8,7,9}};
    Solution s;
    int res = s.firstCompleteIndex(arr,mat);
    cout<<res;
}