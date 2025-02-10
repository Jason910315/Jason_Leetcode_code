#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s[2] = {0,0};  // s[2] 陣列，其中 s[0] 代表滿意時的顧客人數，s[1] 代表不滿意時顧客人數
        int max_s1 = 0;
        for(int i = 0;i < customers.size();i++){
            // 進入窗口
            int satisified = grumpy[i];  // 記錄 i 時間點老闆滿意/不滿意
            s[satisified] += customers[i]; 
            if(i < minutes - 1){  // 直到長度符合 minutes
                continue;
            }
            // 更新窗口內最大不滿意顧客人數
            max_s1 = max(s[1],max_s1);
            // 離開窗口
            if(grumpy[i - minutes + 1] == 1){
                s[1] -= customers[i - minutes + 1];
            }
        }
        return s[0] + max_s1;
    }
};
int main(){
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;

    Solution s;
    int ans = s.maxSatisfied(customers,grumpy,minutes);
    cout<<ans;
}