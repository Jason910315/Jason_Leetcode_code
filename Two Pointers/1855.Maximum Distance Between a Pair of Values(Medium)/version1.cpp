#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int i = 0,j = 0;
    int n = nums1.size(), m = nums2.size();
    int maxDis = 0;
    while(i < n && j < m){
        if(nums1[i] > nums2[j]){
            if(i == j){
                j++;
            }
            i++;
        }
        else{
            maxDis = max(maxDis,j - i);
            j++;
        }
    }
    return maxDis;
}
};

int main(){
    vector<int> nums1 = {50,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};
     
    Solution s;
    int ans = s.maxDistance(nums1,nums2);
    cout<<ans;
}