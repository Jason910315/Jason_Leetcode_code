#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int max_score = 0;
        int l = 0, r = tokens.size() - 1;
        while(l <= r){
            // 當 power >= tokens[l]，可以執行 face down 取得 score
            if(power >= tokens[l]){
                score++;
                power -= tokens[l];
                l++;
                max_score = max(max_score,score);
            }
            // 當 power 沒有大於 tokens[l] 且還有 score 可以抵押時，則執行 face up 借用 tokens[r]
            else if(power < tokens[l] && score >= 1){
                score--;
                power += tokens[r];
                r--;
            }
            // 下述條件即為 power 已不夠但又沒有 score 可以抵押了，只能結束遊戲
            else{
                break;
            }
        }
        return max_score;
    }
};

int main(){
    vector<int> tokens = {100,200,300,400};
    int power = 200;
     
    Solution s;
    int score = s.bagOfTokensScore(tokens,power);
    cout<<score;
}