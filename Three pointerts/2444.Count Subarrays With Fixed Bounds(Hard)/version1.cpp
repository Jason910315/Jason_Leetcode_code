#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int min_i = -1, max_i = -1, lo = -1;
        // 枚舉右端點 i
        for(int i = 0;i < n;i++){
            int x = nums[i];
            // 紀錄 minK、maxK 出現位址
            if(x == minK){
                min_i = i;
            }
            if(x == maxK){
                max_i = i;
            }
            // x 不在 [minK,maxK] 內，更新屏障位址
            if(x < minK || x > maxK){
                lo = i;  
            }
            // 與 0 比大小判斷是否 min_i,max_i 都出現在同一個區間內
            ans += max(min(min_i,max_i) - lo , 0 );
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,5,2,7,5};
    int minK = 1, maxK = 5;

    Solution s;
    int ans = s.countSubarrays(nums,minK,maxK);
    cout<<ans;
}