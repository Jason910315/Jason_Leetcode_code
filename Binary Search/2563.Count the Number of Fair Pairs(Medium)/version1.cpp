#include <vector>
#include <iostream>
#include <algorithm>     
using namespace std;

class Solution {
private:
    // 返回陣列中第一個 >= target 的數的位址
    int lower_bound(int l,int r,vector<int>& nums,int target){
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }

        }
        return l;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;  // 公平數對的數量

        // 枚舉 nums[j]，計算另一數 nums[i] 的範圍內元素個數
        for(int j = 0;j < nums.size();j++){     
            // 計算 < lower - nums[j] 的元素個數 (相當於 >= lower - nums[j] 的第一個元素下標位址)
            int i_lower = lower_bound(0,j - 1, nums,lower - nums[j]);
            // 計算 <= upper - nums[j] 的元素個數 (相當於 > upper - nums[j] 的第一個元素下標位址)
            int i_upper = lower_bound(0,j - 1, nums,upper - nums[j] + 1);
            ans += i_upper - i_lower;  // 代表此合法區間內的 nums[i]
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {0,1,7,4,4,5};
    Solution s;

    int ans = s.countFairPairs(nums,3,6);
    cout<<ans;
}