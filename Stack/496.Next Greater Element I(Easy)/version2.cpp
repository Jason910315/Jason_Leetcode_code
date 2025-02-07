#include <stack>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i = 0;i < nums1.size();i++){
            mp[nums1[i]] = i;
        }
        stack<int> st;  
        int n = nums1.size();
        vector<int> ans(n,-1);
        // 從右到左遍歷
        for(int i = nums2.size()-1;i >= 0;i--){
            int x = nums2[i];
            while(!st.empty() && x >= st.top()){
                st.pop();
            }
            if(!st.empty() && mp.count(x)){
                ans[mp[x]] = st.top();
            }
            st.push(x);
        }
        return ans;
    }
};
int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    Solution s;
    vector<int> answer = s.nextGreaterElement(nums1,nums2);
    for(int i:answer){
        cout<<i<<",";
    }
}