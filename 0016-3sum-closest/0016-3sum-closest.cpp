class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int  left, right, ans = -10000000, sum = 0, n = nums.size();
        for(int i=0;i<n-1;) {
            left = i+1;
            right = n-1;
            while(left<right) {
                sum = nums[i]+nums[left] + nums[right];
                if(sum==target) {
                    return target;
                }
                if(abs(target-sum)<=abs(target-ans)) ans = sum;
                if(sum<target) left++;
                else right--;
            }
            i++;
            while(i<n && nums[i]==nums[i-1])i++;
        }
        return ans;
    }
};