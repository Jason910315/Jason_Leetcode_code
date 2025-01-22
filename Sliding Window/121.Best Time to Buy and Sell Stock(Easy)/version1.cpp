#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int l = 0;
        int r = 1;
        // 此迴圈針對當左方買入價低於右方賣出價時會出現正利潤，才去更新maxProfit
        while(r < prices.size()){
            // 若prices[l] < prices[r],代表新一天的價格能創造正利潤
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit,profit);
            }
            // 否則新一天r的價格會比原先買入價l低，故將r設為新的買入價l
            else{
               l = r;
            }
            r++; // 新一天的價格進入
        }
        return maxProfit;
    }
};
int main(){
    vector<int> prices = {1,5,10,4,6,7,3,9,5};
    Solution s;
    int profit = s.maxProfit(prices);
    cout<<profit;
}