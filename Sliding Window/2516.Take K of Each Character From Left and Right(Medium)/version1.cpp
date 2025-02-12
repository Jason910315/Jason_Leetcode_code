#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt = {0,0,0};  // 記錄窗口外三種字母出現的次數(取走)
        int window = 0;  // 記錄窗口內最大字母個數(未被取走的)
        int l = 0;
        // 先假設取走所有字母，窗口為 0
        for(int r = 0;r < s.length();r++){
            cnt[s[r] - 'a']++;
        }
        // 當有一種字母取出次數 < k，代表字串內該字母個數 < k
        if(cnt[0] < k || cnt[1] < k || cnt[2] < k){
            return -1;
        }
        for(int r = 0;r < s.length();r++){
            cnt[s[r] - 'a']--;  // 將右端點字母加入窗口(不取走)
            while(cnt[s[r] - 'a'] < k){  // 當移出次數 < k
                cnt[s[l] - 'a']++;    // 將字母移出窗口(取走)
                l++;
            }
            window = max(window,r - l + 1);
        }
        return s.length() - window;   // s.length() - window 才是取出的最少次數
    }
};
int main(){
    string str = "aabaaaacaabc";
    int k = 2;

    Solution s;
    int ans = s.takeCharacters(str,k);
    cout<<ans;
    
}