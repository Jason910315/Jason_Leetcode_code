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
        stack<int> st;  // st裡存還未更新"下個更大元素"的元素
        int n = nums1.size();
        vector<int> ans(n,-1);
        // 從左到右遍歷
        for(int i = 0;i < nums2.size();i++){
            int x = nums2[i];
            // x > st.top()，代表x可以成為st.top()元素的"下個更大元素"
            while(!st.empty() && x > st.top()){
                int idx = st.top();
                st.pop();   // 已更新代表無用，丟棄
                ans[mp[idx]] = x;
            }
            // 我們只需計算nums1出現的元素
            if(mp.count(x)){
                st.push(x);
            }
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