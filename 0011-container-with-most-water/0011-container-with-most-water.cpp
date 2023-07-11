class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, ans = 0, volume;
        while(left<right) {
            volume = min(height[left],height[right]) * (right-left);
            ans = max(ans,volume);
            if(height[left]<height[right]) left++;
            else right--;
        }
        return ans;
    }
};