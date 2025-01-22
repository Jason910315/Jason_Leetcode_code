#include <algorithm>
#include <iostream>
#include <unordered_map>
#define INT_MAX 10000000
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // t_map儲存t字串出現過的字符次數，window儲存s字串裡滑動視窗內出現的字符次數
        unordered_map<char, int> t_map, window;
        for (char c:t){
            t_map[c]++;
        }
        int left = 0, right = 0, valid = 0; // left、right控制滑動視窗大小，valid記錄滑動視窗內是否包含所有t字串字符
        int min_len = INT_MAX;
        int start = 0;   // start代表新的子字串起點
        
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (t_map.count(c) == 1) {  // 若新加入的字符出現在t_map裡
                window[c]++;            // 滑動視窗的hash_map新增此字符
                if (window[c] == t_map[c]){  // 代表某個字符數量已滿足
                    valid++;
                }
            }       
            while (valid == t_map.size()) {  // 所有t字符皆已滿足數量
                if (right - left < min_len) {  // 比較子字串的長度並更新最小長度min_len
                    start = left;              // 若有更新代表子字串長度更小，更新起點
                    min_len = right - left;
                }
                char d = s[left];             // 移動左邊指標直到滑動視窗不合法(移除到t字串內的字符)
                left++;
                if (t_map.count(d)) {
                    if (window[d] == t_map[d]) valid--;  // d在此處代表要被移除的字符，若原先window[d] == t_map[d]則代表下一步會不滿足valid規則
                    window[d]--;    // 移除掉d字符，window內的字符數量減1
                }
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
int main(){
    string s = "abc";
    string t = "b";
    Solution sn;
    string ans = sn.minWindow(s,t);
    cout<<ans;
}