class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<2) return nums.size()>0?nums[0]:0;
        return max(findMax(nums,0,nums.size()-2),findMax(nums,1,nums.size()-1));
    }
    
    int findMax(vector<int>& nums, int start, int end) {
        if(start>end) return 0; 
        int prev2 = 0,  prev = nums[start], curr;
        for(int i= start+1;i<=end;i++) {
            curr = max(nums[i]+prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
}; 