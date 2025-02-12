#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int maxLen = 0;
        int l = 0;
        for(int r = 0;r < fruits.size();r++){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                int out = fruits[l];
                mp[out]--;
                if(mp[out] == 0){
                    mp.erase(out);
                }
                l++;
            }
            maxLen = max(maxLen,r - l + 1); 
        }
        return maxLen;
    }
};
int main(){
    vector<int> fruits = {1,2,3,2,2};
    int k = 2;
    Solution s;
    int ans = s.totalFruit(fruits);
    cout<<ans;
}