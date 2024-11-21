// Time:O(n+m),n is the length of string s,m is the length of string t
// Space:O(1),the max length of unordered_map is 26

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false; 
        }
        vector<int> count(26);
        for(int i = 0;i < s.size();i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(auto num:count){
            if(num != 0){
                return false;
            }
        }   
        return true;
    }
};

int main(){
    Solution s;
    string a = "abcdeef";
    string b = "cbaeedf";
    if(s.isAnagram(a,b)){
        cout<<"isAnagram";
    }
    else{
        cout<<"Is not Aragram";
    }
}
