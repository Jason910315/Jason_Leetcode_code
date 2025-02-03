#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 0;
        int dec = 1;  // 嚴格遞減的個數
        int inc = 1;  // 嚴格遞增的個數
        if(nums.size() == 1){
            return 1;
        }
        for(int i = 1;i < nums.size();i++){
            // 遞增
            if(nums[i] > nums[i-1]){   
                inc++;
                dec = 1;  // 遞減個數要降為1
            }
            // 遞減
            else if(nums[i] < nums[i-1]){
                dec++;
                inc = 1;  // 遞增個數要降為1
            }
            else{
                inc = 1;
                dec = 1;
            }
            res = max(max(inc,dec),res);
        }
        return res;
    }
};
int main(){
    vector<int> nums = {1,2,3,5,4,6};
    Solution s;
    int res = s.longestMonotonicSubarray(nums);
    cout<<res;
}