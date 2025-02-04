#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    // 定義閉區間的binary search
    int lowerbound(vector<int> nums,int target){
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] >= target){
                r = mid - 1;
            }
            else{   // nums[mid] < target
                l = mid + 1;
            }
        }
        return l;  // 因為l-1始終<target，l為第一個>=target的位址
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // start為>=target
        int start = lowerbound(nums,target);
        // 若start維陣列長度，代表陣列中所有元素都<target
        if(start == nums.size() || nums[start] != target){
            return {-1,-1};
        }
        // end為<=target 
        int end = lowerbound(nums,target+1)-1;
        return {start,end};
    }
};

int main(){
    vector<int> nums = {1,2,3,5,6,7,8,8,10,11};
    Solution s;
    vector<int> ans = s.searchRange(nums,8);
    for(int v:ans){
        cout<<v<<",";
    }
}