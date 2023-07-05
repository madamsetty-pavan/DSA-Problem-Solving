class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0 , flag = 0, n = nums.size(), ans=0;
        for(int left = 0, right = 0; right < n; right++) {
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
        }
        if(!flag) return n-1;
        return ans;
    }
};