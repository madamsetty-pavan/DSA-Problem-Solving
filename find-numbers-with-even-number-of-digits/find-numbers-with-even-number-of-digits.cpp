class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans =0 ;
        for(int i=0;i<nums.size();i++) {
            int log1 = ( 1 + log10(nums[i]));
            ans += log1%2 == 0;
        }
        return ans;
    }
};