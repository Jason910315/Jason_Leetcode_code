#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0;
        long long sum = 0;  // sum 為 actual sum
        int ans = 0;
        for(int r = 0;r < nums.size();r++){
            sum += nums[r];  // 新的 target 進入 sliding window
            // target sum - actual sum 的次數大於 k 時，代表修改超過限制，視窗不合法
            while((long long)nums[r] * (r - l + 1) - sum > k){
                sum -= nums[l];  // 左端點離開滑動視窗
                l++;
            }
            ans = max(ans,r - l + 1);
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {1,4,8,13};
    int k = 5;

    Solution s;
    int ans = s.maxFrequency(nums,k);
    cout<<ans;
}