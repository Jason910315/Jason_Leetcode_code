#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int sum = nums[0];
        if(nums.size() == 1){
            return sum;
        }
        for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];         
            }
            else{
                maxSum = max(sum,maxSum);
                sum = nums[i];
            }
        }
        return max(sum,maxSum);  // 防止subarray遞增到陣列結束時少了判斷max的步驟
    }
};
int main(){
    vector<int> nums = {100,10,0};
    Solution s;
    int res = s.maxAscendingSum(nums);
    cout<<res;
}