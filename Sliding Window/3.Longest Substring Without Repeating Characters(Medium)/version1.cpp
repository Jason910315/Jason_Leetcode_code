#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char,int> cnt;  // 儲存每個字符出現的次數
        int l = 0;  // l模擬從左邊加入的字符
        // r模擬從右邊加入的字符，以l、r兩個指針做滑動視窗
        for(int r = 0;r < s.length();r++){
            cnt[s[r]]++;
            while(cnt[s[r]] > 1){  // 若s[r]字符重複出現，則不斷移出左邊字符直到沒有重複
                cnt[s[l]]--;
                l++;  // 移出左邊字符       
            }
            maxLen = max(maxLen,r-l+1);
        }    
        return maxLen;
    }
};

int main(){
    string str = "pwwkew";
    Solution s;
    int ans = s.lengthOfLongestSubstring(str);
    cout<<ans;
}