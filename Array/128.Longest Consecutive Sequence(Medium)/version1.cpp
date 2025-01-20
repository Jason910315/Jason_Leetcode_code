#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq(nums.begin(),nums.end());
        int max_length = 0;
        int length;
        for(int num:seq){
            if(seq.find(num-1) == seq.end()){
                length = 1;
                while(seq.find(num+length) != seq.end()){
                    length++;
                }
                max_length = max(length,max_length);
            } 
        }
        return max_length;
    }
};
int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution s;
    int res = s.longestConsecutive(nums);
    cout<<res;
}