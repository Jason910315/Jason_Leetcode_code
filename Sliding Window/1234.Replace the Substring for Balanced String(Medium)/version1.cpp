#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        int bal = n/4;   // 計算每個字母需出現的次數
        int cnt['X']{};  // cnt 陣列儲存每個字母出現的次數，且維護的是「欲被替換字母以外」的字符
        int ans = n + 1;
        // 先遍歷整個陣列計算每個字母出現次數
        for(int i = 0;i < n;i++){
            cnt[s[i]]++;
        }
        // 每個字母都出現 bal 次，代表 balance
        if(cnt['Q'] == bal && cnt['W'] == bal && cnt['E'] == bal && cnt['R'] == bal){
            return 0;
        }

        int l = 0;
        // 若有字母出現次數 > bal，則進行以下迴圈
        for(int r = 0;r < n;r++){
            cnt[s[r]]--;  // 將 s[r] 加進欲被替換字母中
            // 「欲被替換字母以外」的字母數量皆已符合 <= bal，代表合法
            while(cnt['Q'] <= bal && cnt['W'] <= bal && cnt['E'] <= bal && cnt['R'] <= bal){
                // 計算合法視窗長度並下一步縮小視窗長度
                ans = min(ans,r - l + 1);
                cnt[s[l]]++;
                l++;
            }
        }
        return ans;
    }
};
int main(){
    string str = "QQQW";

    Solution s;
    int ans = s.balancedString(str);
    cout<<ans;
}