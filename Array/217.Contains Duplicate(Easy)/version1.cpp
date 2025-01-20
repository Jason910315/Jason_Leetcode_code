// Time:O(n)
// Space:O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        // 使用unordered_set用來儲存唯一的元素
        unordered_set<int> duplicate; 
        for(int num:nums)
        {
            if(duplicate.count(num) > 0) // 檢查num是否存在set裡
            {
                return true;
            }
            duplicate.insert(num); // 若不存在則加入元素，等下次有重複元素時便會發現
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,1,2,4,5,8,8};
    if(s.containsDuplicate(nums)){
        cout<<"Has Duplicate";
    }
    else{
        cout<<"Has no duplicate";
    }
}
