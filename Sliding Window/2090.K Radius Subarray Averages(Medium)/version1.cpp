#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avg(nums.size(),-1);
        long long sum = 0;
        // 滑動窗口長度設為 k*2+1
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            if(i < 2*k){         
                continue;
            }
            // 計算平均量
            avg[i - k] = sum / (2*k + 1);
            // 從前端離開一個元素
            sum -= nums[i-2*k];
        }
        return avg;
    }
};
int main(){
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    Solution s;
    vector<int> avg = s.getAverages(nums,k);
    for(int i : avg){
        cout<<i<<",";
    }
}