#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
     // 相向雙指針法
     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> closer(k);
        int l = 0, r = arr.size() - 1;
        int del = arr.size() - k;
        while(l < r && del > 0){
            if(x - arr[l] <= arr[r] - x){
                r--;
            }
            else{
                l++;
            }
            del--;
        }
        for(int i = 0;i < k;i++){
            closer[i] = arr[l + i];
        }
        return closer;   
    }
};

int main(){
    vector<int> arr = {1,1,2,3,4,5};
    int k = 4;
    int x = -1;
     
    Solution s;
    vector<int> ans = s.findClosestElements(arr,k,x);
    for(int i : ans){
        cout<<i<<",";
    }
}