#include <iostream>
#include <unordered_set>
#include <math.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int cnt = pow(2,k);  // 長度 k 的二進制個數有 2^k 個 
        unordered_set<string> st;
        string sub;
        // s 長度 < 2^k，必不可能包含所有二進制
        if(s.length() < cnt){
            return false;
        }
        for(int i = 0;i < s.length();i++){
            // 索引 i 的字符進入滑動窗口
            sub += s[i]; 
            if(i < k -1){
                continue;
            }
            // set 更新唯一的 sub 字串(二進制字串)
            st.insert(sub);
            // 移除第一位字符
            sub = sub.substr(1);  
        }
        return st.size() >= cnt ? true : false;
    }
};
int main(){
    string str = "00110110";

    Solution s;
    int k = 2;
    bool ans = s.hasAllCodes(str,k);
    cout<<ans;
}