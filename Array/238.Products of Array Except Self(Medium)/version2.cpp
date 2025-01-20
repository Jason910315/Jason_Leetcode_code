#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int i;
        vector<int> result(n);
        result[0] = 1;
        for(i = 1;i < n;i++){
            result[i] = result[i-1] * nums[i-1];
        }
        int right = 1;
        for(i = n-1;i >= 0 ;i--){
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,2,4,6};
    Solution s;
    vector<int> res = s.productExceptSelf(nums);
    for(int s:res){
        cout<<s<<",";
    }
}