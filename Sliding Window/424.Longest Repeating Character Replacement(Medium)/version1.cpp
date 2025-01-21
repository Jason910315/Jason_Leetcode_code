#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0; // 記錄目前最長字串長度
        int l = 0;
        int max_valueCount = 0;
        unordered_map<char,int> cntValue;  // 記錄滑動視窗內出現的每個字符數量
        for(int r = 0;r < s.length();r++){
            cntValue[s[r]]++;  
            // 上一步紀錄的max_valueCount與這一步新加入的字符數量去比
            max_valueCount = max(max_valueCount,cntValue[s[r]]);
            while((r-l+1 - max_valueCount) > k){
                    cntValue[s[l]]--;
                    l++;
                }
            res = max((r-l+1),res);
        }
        return res;
    }
};

int main(){
    string str = "AABABBA";
    int k = 2;
    Solution s;
    int ans = s.characterReplacement(str,k);
    cout<<ans;
}