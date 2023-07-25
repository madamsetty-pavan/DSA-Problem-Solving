class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n>0?nums[0]:0;
        return max(findMax(nums,0,n-2),findMax(nums,1,n-1));
    }
    
    int findMax(vector<int>& nums, int start, int end) {
        int prev2 = 0,  prev = nums[start], curr;
        for(int i= start+1;i<=end;i++) {
            curr = max(nums[i]+prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
}; 