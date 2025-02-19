#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;
        int i = 0, j = plants.size() - 1;
        int a = capacityA;
        int b = capacityB;
        while(i < j){
            // 若 i 位址植物需要水量超過 a，則要灌滿水
            if(plants[i] > a){
                a = capacityA;
                ans++;
            }
            a -= plants[i];
            i++;  // i 向右移動

            // 若 j 位址植物需要水量超過 b，則要灌滿水
            if(plants[j] > b){
                b = capacityB;
                ans++;
            }
            b-= plants[j];
            j--;  // j 向左移動
        }
        // 若遍歷結束後 i == j，代表兩個人來到同一個植物
        if(i == j && max(a,b) < plants[i]){
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,2,3,4};

}