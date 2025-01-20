#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // 先排序陣列花O(n2)
        sort(nums.begin(),nums.end());
        // 遍歷排序後的陣列，尾端要保留兩個元素給l、r
        for(int i = 0;i < nums.size()-2;i++){
            // 若第一個元素nums[i]>0，則sum必不等於0
            if(nums[i] > 0) break;
            // 避免有重複的三元組
            if(i > 0 && nums[i] == nums[i-1]) continue;
            else{
                int l = i + 1;
                int r = nums.size() - 1;
                while(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum > 0){
                        r--;
                    }
                    else if(sum < 0){
                        l++;
                    }
                    else{
                        res.push_back({nums[i],nums[l],nums[r]});
                        l++;
                        r--;
                        // 跳過重複的l、r
                        while(l < r && nums[l] == nums[l-1]){
                            l++;
                        }
                        while(l < r && nums[r] == nums[r+1]){
                            r--;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};

    Solution s;
    vector<vector<int>> res = s.threeSum(nums);
    cout << "[";
    for (vector<int> r : res) { 
        cout << "[";
        for (size_t i = 0; i < r.size(); i++) {
            cout << r[i];
            if (i != r.size() - 1) cout << ", ";  // 避免最後一個元素後面多印逗號
        }  
        cout << "], ";
    }
    cout << "]";
    cout << endl;
}