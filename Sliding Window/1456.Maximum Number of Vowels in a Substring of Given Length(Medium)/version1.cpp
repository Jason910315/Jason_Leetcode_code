#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;     // 最大 vowels 數
        int vowels = 0;  // 統計視窗內 vowels 數
        for(int i = 0;i < s.length();i++){
            char in = s[i];
            // 入
            if(in == 'a' || in == 'e' || in == 'i' || in == 'o' || in == 'u'){
                vowels++;
            }
            // 持續進入直到長度符合 k
            if(i < k-1){
                continue;
            }
            // 更新最大值
            ans = max(vowels,ans);
            // 出
            char out = s[i-k+1];
            if(out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u'){
                vowels--;
            }
        }
        return ans;
    }
};
int main(){
    string str = "abciiidef";

    Solution s;
    int vowels = s.maxVowels(str,3);
    cout<<vowels;
}