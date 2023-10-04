// Single time
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxP = 1, minP = 1, n = nums.size(), ans = INT_MIN;
//         for(int i=0;i<n;i++) {
//             if(nums[i]<0) swap(maxP,minP);
//             maxP = max(nums[i], maxP * nums[i]);
//             minP = min(nums[i], minP * nums[i]);
//             ans = max(ans, maxP);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefP = 1, sufP = 1, ans = INT_MIN, n= nums.size();
        for(int i=0;i<n;i++) {
            prefP *= nums[i];
            sufP *= nums[n-1-i];
            ans = max(ans, max(prefP, sufP));
            if(prefP ==0) prefP = 1;
            if(sufP == 0) sufP = 1;
        }
        return ans;
    }
};
