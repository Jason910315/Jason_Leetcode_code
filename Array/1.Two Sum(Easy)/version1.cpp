// Time:O(n2)
// Space:O(n)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int res;
        for(int i = 0;i < nums.size();i++){
            res = target - nums[i]; 
            for(int j = i + 1;j < nums.size();j++){
                if(nums[j] == res){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result; 
    }
};

int main(){
    vector<int> nums{3,2,4,2};
    int target = 6;
    Solution s;
    vector<int> result = s.twoSum(nums,target);
    for(auto i:result){
        cout<<i<<",";
    }
}