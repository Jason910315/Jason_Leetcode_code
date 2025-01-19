// Time:O(n)
// Space:O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> value;
        int res;
        for(int i = 0;i < nums.size();i++){
            value[nums[i]] = i;
        }
        for(int i = 0;i < nums.size();i++){
            res = target - nums[i];
            // 若兩數差值存在於 unoredred_map 裡且與 nums 陣列的 index 不同
            if(value.count(res) && i != value[res]){
                return {i,value[res]};
            }
        }
        return{};
    }
};

int main(){
    vector<int> nums{3,2,8};
    int target = 6;
    Solution s;
    vector<int> result = s.twoSum(nums,target);
    for(auto i:result){
        cout<<i;
    }
}