#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    int MOD = 1000000007;
    // 計算 a 的 b 次方在 mod 10^9+7 下的結果 
    long long power(long long a,long long b){
        a = a % MOD;
        long long res = 1;
        while(b > 0){
            if(b & 1){
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        int i = 0, j = n - 1;
        // 左端點當作最小值
        // 右端點為最大值
        while(i <= j){
            // 若最小值 + 最大值小於 target，代表[i + 1,j]區間內的組合都可作為 subsequence
            if(nums[i] + nums[j] <= target){
                int len = j - i + 1;
                // 區間內可提供 2^len-1 次個答案(區間長度為 len)
                ans = (ans + power(2,len - 1)) % MOD;
                i++;  // i 移動增加最小值
            }
            // 最小值 + 最大值 > target，j 要移動以減小最大值
            else{
                j--;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,3,3,4,6,7};
    int target = 12;

    Solution s;
    int ans = s.numSubseq(nums,target);
    cout<<ans;
}