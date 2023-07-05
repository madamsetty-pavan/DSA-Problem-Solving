class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0,right =0, count =0 , flag = 0, n = nums.size(), ans=0;
        while(right<n) {
            if(nums[right] ==0) {
                flag = 1;
                count++;
                while(count>1) {
                    if(nums[left]==0) {
                        count--;
                    } 
                    left++;
                }
            }
            ans = max(ans, right-left);
            right++;
        }
        if(!flag) return n-1;
        return ans;
    }
};