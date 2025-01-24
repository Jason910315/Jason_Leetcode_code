#include <vector>
#include <iostream>
#include <cmath>     
using namespace std;
class Solution {
public:
    // 定義helper函數，接收speed參數後計算此速度所需的列車行駛總時間為多少
    double helper(vector<int>& dist, int speed){
        double total_time = 0.0;
        int n = dist.size();
        // 循環至n-1，因為最後一站的時間是浮點數，不用計算上界，需額外計算
        for(int i = 0;i < n-1;i++){
            // 每站行駛時間需取上界再相加
            total_time += ceil((double)dist[i] / speed);
        }
        total_time += (double)dist[n-1] / speed;  // 計算最後一站行駛的時間
        return total_time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // 上下界設為1~10^7
        int l = 1;
        int r = 1e7;
        int res = -1;  // 記錄可行速度
        while(l <= r){
            int speed = l + (r-l)/2;
            double time = helper(dist,speed);
            if(time <= hour){
                // 此速度是可行的，先記錄下來，並持續找更小的速度，故r = speed -1;
                res = speed;
                r = speed - 1;
            }
            else if(time > hour){
                l = speed + 1;
            }
        }
        return res;
    }
};
int main(){
    vector<int> dist = {3,4,6,7};
    Solution s;
    int hour = 7;
    int ans = s.minSpeedOnTime(dist,7);
    cout<<ans;
}