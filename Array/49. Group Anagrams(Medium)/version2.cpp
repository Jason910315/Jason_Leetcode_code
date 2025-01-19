// Time:O(m*n),n 為字串陣列裡最長陣列的長度，m 為字串陣列的元素個數
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
        unordered_map<string,vector<string>> res;
        for(auto &s:strs){
            vector<int> count(26);  // count 紀錄字串中字母的出現頻率
            for(auto ch:s){
                count[ch - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1;i < 26;i++){
                key += "," + to_string(count[i]);  // key 最終為 1,0,1,...1 這種形式，表示某字串的字母出現頻率
            }
            res[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &pair : res){
            ans.push_back(pair.second);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"bdddddddddd","bbbbbbbbbbc"};
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
