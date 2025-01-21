#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 使用雙指針從頭尾遍歷
       int i = 0;
       int j = height.size()-1;
       int currentArea = (j - i) * min(height[i],height[j]); // currentArea儲存目前水量面積
       int maxArea = currentArea; 
       while(i < j){
            // 比較i,j指標對應的高度，較小高度的指針移動
            if(height[i] <= height[j]){
                i++;
            }
            else{
                j--;
            }
            // 計算目前面積，並不斷與maxArea比較
            currentArea = (j - i) * min(height[i],height[j]);
            maxArea = max(maxArea,currentArea);
       }
       return maxArea;
    }
};

int main(){
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int maxArea = s.maxArea(heights);
    cout<<maxArea;
}