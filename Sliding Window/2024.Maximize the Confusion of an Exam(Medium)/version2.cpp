#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<int> &pre,int k,int n,int mid){
        // l、r 為每次區間的範圍，其長度都是 mid
        for(int l = 0,r = l + mid - 1;r < n;l++,r++){
            int sumT = pre[r + 1] - pre[l];  // [l,r] 內 'T' 個數
            int sumF = r - l + 1 - sumT;     // [l,r] 內 'F' 個數
            // 此長度只要找到一個合法的子字串，即返回 true
            if(sumT <= k || sumF <= k){
                return true;
            }
        }
        return false;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        vector<int> pre(n + 1);
        // 計算 prefix sum 
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (answerKey[i] == 'T' ? 1 : 0);
        }
        int left = 0;
        int right = n;
        while(left <= right){
            int mid = left + (right - left)/2;  // mid 為此次檢查的視窗"長度"
            if(isValid(pre,k,n,mid)){
                left = mid + 1;   // mid 長度合法，繼續往右找更大長度
            }
            else{
                right = mid - 1;
            }
        }
        return right;
    }
};
int main(){
    string answerKey = "TTTFFTTFFT";
    int k = 2;
    Solution s;
    int ans = s.maxConsecutiveAnswers(answerKey,k);
    cout<<ans;
}