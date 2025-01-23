#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // step1:先尋找pivot(將nums分為兩個升序陣列的點)
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]){  // 代表pivot在右邊的區間
                left = mid + 1;
            }
            else{  
                right = mid;
            }     
        }
        int pivot = left; // pivot為更小的子陣列的起點
        // 上述做完後會得到三個點[left,pivot,right]

        // step2:判斷target應位於哪個子陣列，要注意此處pivot是較小陣列的起點
        left = 0;
        right = nums.size()-1;
        // pivot是分界點，下述條件會在target位於右區間時成立
        if(target >= nums[pivot] && target <= nums[right]){
            left = pivot;  
        }
        else{  
            right = pivot-1;
        }
        // step3: 上述已確定target位於的區間且對left、right做處理，以下做一般的binarySearch即可
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {6,7,8,9,10,11,1,2,3,4,5};
    Solution s;
    int ans = s.search(nums,3);
    cout<<ans;
}