#include <vector>
#include <iostream>   
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // 找第一個 > target 的元素(相當於 >= target + 1)
        int n = letters.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r -l)/2;
            if(letters[mid] - 'a' < target - 'a' + 1){
                l = mid + 1;
            }
            else if(letters[mid] - 'a' >= target - 'a' + 1){
                r = mid - 1;
            }
        }
        return l == n ? letters[0] : letters[l];
    }
};
int main(){
    vector<char> letters = {'c','d','f'};
    char target = 'c';

    Solution s;
    char ans = s.nextGreatestLetter(letters,target);
    cout<<ans;
}