// Time:O(n+m),n is the length of string s,m is the length of string t
// Space:O(1),the max length of unordered_map is 26

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false; 
        }
        unordered_map<char,int> sData;
        unordered_map<char,int> tData;
        for(int i = 0;i < s.size();i++){
            sData[s[i]]++;  // 將出現的英文字母的雜湊值加1
            tData[t[i]]++;
        }
        return sData == tData;     
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
