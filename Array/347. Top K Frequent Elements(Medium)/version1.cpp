// Time:O(n)，n 為 nums 長度
// Space:O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size() + 1);  // 要初始化 freq 長度，以免取值 out of bounds
        for(auto s : nums){
            count[s]++;  // 紀錄每個數字出現次數
        }
        // 用 bucket sort，將每個數字填入其出現次數的籃子裡
        for(auto &pair : count){
            freq[pair.second].push_back(pair.first);
        }

        vector<int> ans;
        // 由大到小取回來
        for(int i = freq.size() - 1;i > 0 ;i--){
            for(auto num : freq[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;  
    }
};


int main(){
    vector<int> nums = {1,2,2,3,3,3};
    Solution s;
    vector<int> ans = s.topKFrequent(nums,2);
    for(auto n:ans){
        cout<<n<<",";
    }
}