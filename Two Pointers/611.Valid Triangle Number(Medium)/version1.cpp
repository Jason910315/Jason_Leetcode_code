#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        // 設三角形三邊長為 index i,j,k，且 i < j < k，枚舉 k
        for(int k = 2;k < nums.size();k++){
            int c = nums[k];  // c 為第三邊邊長
            // i、j 為其他兩邊的元素上下區間
            int i = 0;
            int j = k - 1;
            while(i < j){
                if(nums[i] + nums[j] > c){
                    // 由於 nums 已排序，故若 nums[i] + nums[j] > c
                    // 則 nums[i + ...] + nums[j] 都必定大於 c，i、j 區間內的數都可以作為邊長組合
                    ans += j - i;
                    j--;  // j 變小嘗試其他 nums[j] 可否成為第二邊
                }
                else{
                    // nums[i] + nums[j] 太小，故增加 i 加大 nums[i]
                    i++;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,2,3,4};

    Solution s;
    int ans =s.triangleNumber(nums);
    cout<<ans;
    
}