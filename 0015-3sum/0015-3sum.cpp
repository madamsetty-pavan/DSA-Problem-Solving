class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++) {
            while(i<n && i>=1 && nums[i]==nums[i-1]) i++;
            int left = i+1, right = n-1, sum=0;
            while(left<right) {
                sum = nums[i] + nums[left] + nums[right];
                if(sum==0){
                    ans.push_back({nums[left],nums[right],nums[i]});
                    left++;
                    right--;
                    while(left<n && nums[left]==nums[left-1]) left++;
                    while(right>=0 && nums[right]==nums[right+1]) right--;
                } else if(sum<0) left++;
                else right--;
            }
        }
        return ans;
    }
};