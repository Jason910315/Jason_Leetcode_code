#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        int BIAS = 50;  // 偏差值
        vector<int> cnt(BIAS*2 + 1);  // 所有可能出現元素的 bucket
        // 先計算到 k-1 個元素以便下次元素進入即符合窗口長度
        for(int i = 0;i < k-1;i++){
            cnt[nums[i] + BIAS]++;
        }
        for(int i = k-1;i < n;i++){
            // 入
            cnt[nums[i] + BIAS]++;
            int left = x;
            // 只需遍歷 cnt 的前 50 個數，題目規定 beauty 只存在負數間
            for(int j = 0;j < BIAS;j++){
                left -= cnt[j];   // left 減去由小到大負數出現的次數
                if(left <= 0){    // 找到第 x 小的數
                    ans[i - k + 1] = j - BIAS;
                    break;
                }
            }
            // 離開窗口
            cnt[nums[i - k + 1] + BIAS]--;
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {-3,1,2,-3,0,-3};
    int k = 2;
    int x = 1;

    Solution s;
    vector<int> ans = s.getSubarrayBeauty(nums,k,x);
    for(int i : ans){
        cout<<i<<",";
    }
}