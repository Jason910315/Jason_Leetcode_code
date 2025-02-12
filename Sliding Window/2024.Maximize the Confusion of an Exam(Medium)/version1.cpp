#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int max_ans = 0;
        vector<int> cnt = {0,0};   // 記錄視窗內'T'、'F'出現次數
        int l = 0;
        for(int r = 0;r < n;r++){
            cnt[answerKey[r] >> 1 & 1]++;  // 可判斷 answerKey[r] 為'T'還是'F'
            // 當窗口內 'T'、'F'個數皆 > K 時
            while(cnt[0] > k && cnt[1] > k){
                cnt[answerKey[l] >> 1 & 1]--;  // 剃除 l 位址的元素
                l++;  // l 前進
            }
            max_ans = max(max_ans,r - l + 1);
        }
        return max_ans;
    }
};
int main(){
    string answerKey = "TTTFFTTFFT";
    int k = 2;
    Solution s;
    int ans = s.maxConsecutiveAnswers(answerKey,k);
    cout<<ans;
}