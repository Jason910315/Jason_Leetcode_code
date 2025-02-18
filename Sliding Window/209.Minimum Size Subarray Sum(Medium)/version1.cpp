#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        int sum = 0;
        int l = 0;
        for(int r = 0;r < n;r++){
            sum += nums[r];
            // 一旦 sum >= target，即符合題目條件，則計算滑動視窗長度
            while(sum >= target){
                ans = min(ans,r - l + 1);
                // 左端點向前進，縮小滑動視窗，以便下次 while 判斷是否符合題目
                sum -= nums[l];
                l++;
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};
int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    Solution s;
    int ans = s.minSubArrayLen(target,nums);
    cout<<ans;
}