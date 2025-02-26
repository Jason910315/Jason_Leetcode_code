#include <vector>
#include <iostream> 
#include <algorithm>   
using namespace std;

class Solution {
public:
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> pairs;
    int n = spells.size(), m = potions.size();
    sort(potions.begin(),potions.end());
    // 枚舉 spells 陣列的每個元素
    for(int i = 0;i < n;i++){
        int left = 0, right = m - 1;
        // 對 potions 陣列二分查找找第一個 spell * potion >= successful 的 potion
        while(left <= right){
            int mid = left + (right - left)/2;
            // 因 success 是 long long，故乘法前須先轉型
            if((long long)spells[i] * potions[mid] < success){
                left = mid + 1;
            }
            else if((long long)spells[i] * potions[mid] >= success){
                right = mid - 1;
            }
        }
        int successful = left == m ? 0 : m - left;
        pairs.push_back(successful);
    }
    return pairs;
}
};
int main(){
    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5};
    int success = 7;

    Solution s;
    vector<int> pairs = s.successfulPairs(spells,potions,success);
    for(int i : pairs){
        cout<<i<<",";
    }
}