#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[right]) {
                left = mid + 1;
            } 
            else if(nums[mid] < nums[right]){
                right = mid;
            }
        }
        return nums[left];
    }
};

int main(){
    vector<int> nums = {4,6,7,8,9,2,3,4};
    Solution s;
    int ans = s.findMin(nums);
    cout<<ans;
}