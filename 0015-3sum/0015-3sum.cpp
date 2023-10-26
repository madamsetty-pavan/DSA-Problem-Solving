class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), i = 0 ;
        if(n<3) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        while(i<n) {
            int left = i+1;
            int right = n-1;
            while(left<right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(sum>0) {
                    right --;
                } else if(sum <0) {
                    left++;
                } else {
                    ans.push_back({nums[left],nums[i],nums[right]});
                    left++;
                    right--;
                    while(left< right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
            }
            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};