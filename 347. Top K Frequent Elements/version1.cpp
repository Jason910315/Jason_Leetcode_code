// Time:O(n)
// Space:O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq;
        vector<int> ans;
        for(auto n : nums){
            count[n]++;
        }
        for(auto &pair : count){
            freq[pair.second].push_back(pair.first);
        }

        for(int i = freq.size()-1;i >= 0 ;i--){
            for(int num : freq[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    break;
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