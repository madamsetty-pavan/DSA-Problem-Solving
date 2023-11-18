// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int maxHeight = 0, maxIndex = 0;
//         for(int i=0;i<height.size();i++) {
//             if(maxHeight < height[i]) {
//                 maxHeight = height[i];
//                 maxIndex = i;
//             }
//         }
//         int leftMax = 0 , rightMax = 0, ans = 0;
//         for(int i=0;i<maxIndex;i++) {
//             leftMax = max(leftMax, height[i]);
//             ans += min(leftMax, maxHeight) - height[i];
//         }
//         for(int i = height.size()-1; i>maxIndex; i--) {
//             rightMax = max(rightMax, height[i]);
//             ans += min(rightMax, maxHeight) - height[i];
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0, rightMax = 0, left = 0, right = height.size()-1, ans = 0;
        while(left < right) {
            if(height[left] <= height[right]) {
                leftMax = max(height[left], leftMax);
                ans += leftMax - height[left];
                left++;
            }  else {
                rightMax = max(height[right], rightMax);
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};