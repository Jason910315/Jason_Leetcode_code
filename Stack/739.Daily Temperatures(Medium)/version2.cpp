#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 從右到左遍歷
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n-1;i >= 0;i--){
            int t = temperatures[i];
            // 向左遍歷遇到更高溫度，將stack裡更低溫的下標通通刪除
            while(!st.empty() && t >= temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top() - i;
            }
            st.push(i);
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