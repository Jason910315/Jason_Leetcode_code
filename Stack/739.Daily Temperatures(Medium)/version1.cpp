#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 從左到右遍歷
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;  // stack裡儲存還未更新完畢的溫度"索引"
        vector<int> ans(n);  // ans儲存答案 
        for(int i = 0;i < n;i++){
            int t = temperatures[i];
            // 當stack不為空且當前溫度大於stack的頂端溫度，代表遇到更高溫度，stack裡的天數都要更新
            while(!st.empty() && t > temperatures[st.top()]){
                int j = st.top(); // j為溫度位址 
                st.pop();
                ans[j] = i - j;  // 第i位址溫度更高，天數j-i
            }
            st.push(i);  // 溫度索引還未更新，加進stack裡等待
        }
        return ans;
    }
};
int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution s;
    vector<int> answer = s.dailyTemperatures(temperatures);
    for(int i:answer){
        cout<<i<<",";
    }
}