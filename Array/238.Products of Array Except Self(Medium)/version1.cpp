#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i,n = nums.size();
        vector<int> ans(n);
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        leftProduct[0] = 1;
        for(i = 1;i < n;i++){
            leftProduct[i] = leftProduct[i-1] * nums[i-1]; 
        }
        rightProduct[n-1] = 1;
        for(i = n-2;i >= 0;i--){
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        }
        for(i = 0;i < n;i++){
            ans[i] = leftProduct[i] * rightProduct[i];
        }
        return ans;
        
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