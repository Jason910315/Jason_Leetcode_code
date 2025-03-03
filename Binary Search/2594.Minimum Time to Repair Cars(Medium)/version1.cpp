#include <vector>
#include <iostream> 
#include <algorithm>
#include <cmath>     
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        long long ans = 0;
        // [l,r] 區間代表時間 t
        long long l = 0;
        long long r = (long long)ranks[0] * cars * cars;  // 修理所有車子最多花 r 時間
        // 閉區間寫法，對時間 t 做二分 
        while(l <= r){
            long long  mid = l + (r - l)/2;
            long long sum = 0;  
            // 計算 mid 時間下所有技師可以修的汽車總數
            for(int r : ranks){
                sum += floor(sqrt(mid / r));
            }
            // 若 mid 時間下可以修完所有汽車，則向左搜尋更短時間
            if(sum >= cars){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
int main(){
    vector<int> ranks = {4,2,3,1};
    int cars = 10;

    Solution s;
    int ans = s.repairCars(ranks,cars);
}