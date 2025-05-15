
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int l = 0;
        long long ans = 0;
        int cnt = 0;
        int mx = *max_element(nums.begin(),nums.end());
        for(int r = 0;r < nums.size();r++){
            if(nums[r] == mx){
                cnt++;
            }
            if(cnt == k){
                while(cnt == k){
                    if(nums[l] == mx){
                        cnt--;
                    }
                    l++;
                }
            }
            ans += l;
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {1,3,2,1,3,2,1,3};
    int k = 2;
    Solution s;
    int ans = s.countSubarrays(nums,k);
    cout<<ans;
}