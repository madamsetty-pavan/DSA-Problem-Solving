class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedArray(heights);
        sort(sortedArray.begin(), sortedArray.end());
        int ans =0;
        for(int i=0;i<heights.size();i++) {
            if(heights[i]!=sortedArray[i]) ans++;
        }
        return ans;
    }
};