class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int left , right, n =nums.size(), sum;
        for(int i=0;i<n;) {
            left = i+1;
            right = n-1;
            while(left<right) {
                sum = nums[left] + nums[right] + nums[i];
                if(sum>0) {
                    right --;
                } else if(sum<0) {
                    left++;
                }
                else {
                    ans.push_back({nums[left],nums[right], nums[i]});
                    left++;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    right--;
                    while(left<right && nums[left]==nums[right+1]) right--;
                }
            }
            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};