// Time:O(m*nlogn),n 為字串陣列裡最長陣列的長度，m 為字串陣列的元素個數
// Space:O(m*n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm> 

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(const auto &s:strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());  // 排序字串，花 nlogn
            m[sorted].push_back(s);  // 將原字串 s 加入符合其排序結果的位置
        }
        vector<vector<string>> ans;
        for(auto &pair:m){   // m 為 map。故會返回兩個值，<index,value>
            ans.push_back(pair.second);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    vector<vector<string>> result;
    result = s.groupAnagrams(strs);
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
}
