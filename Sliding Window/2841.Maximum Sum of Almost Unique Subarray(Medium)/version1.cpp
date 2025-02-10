#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 題目給予 k，固定長度數組，用定長滑動窗口解
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum = 0;  // 記錄滑動視窗內元素加總
        long long max_sum = 0;
        unordered_map<int,int> mp;  // 記錄滑動視窗內元素出現次數

        // 遍歷前 k-1 個元素
        for(int i = 0;i < k-1;i++){
            mp[nums[i]]++;
            sum += nums[i];
        }
        // 進入後窗口就變為 k 個元素
        for(int i = k-1;i < nums.size();i++){
            // 入
            sum += nums[i];
            mp[nums[i]]++;
            // 若符合"almost unique"條件，則更新統計量
            if(mp.size() >= m){
                max_sum = max(sum,max_sum);
            }
            // 出
            int out = nums[i - k + 1];  // 離開窗口的元素
            mp[out]--;
            sum -= out;
            if(mp[out] == 0){  // 某元素出現次數為 0 就要從 mp 中移除
                mp.erase(out);
            }
        }
        return max_sum;
    }
};
int main(){
    vector<int> nums = {5,9,9,2,4,5,4};
    int k = 3;
    int m = 3;

    Solution s;
    int ans = s.maxSum(nums,m,k);
    cout<<ans;
}