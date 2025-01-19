#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0;i < strs.size();i++){
            res += to_string(strs[i].length()) + "#" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.length()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i,j - i));
            i = j + 1;         
            string str = s.substr(i,length);
            res.push_back(str);
            j = i + length;
            i = j;
        }
        return res;
    }
};

int main(){
    vector<string> strs = {"Neet","Code"};
    Solution s;
    string str = s.encode(strs);
    vector<string> res = s.decode(str);
    for(const string r:res){
        cout<<r<<",";
    }
}
