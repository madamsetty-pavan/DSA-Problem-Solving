class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int  left, right, ans = INT_MAX, sum = 0, n = nums.size();
        for(int i=0;i<n-1;i++) {
            left = i+1;
            right = n-1;
            while(left<right) {
                sum = nums[i]+nums[left] + nums[right];
                if(sum==target) return target;
                // update limits
                if(sum<target) left++;
                else right--;
                // update answer
                if(ans==INT_MAX)  ans = sum;
                else if (abs(target-sum)<=abs(target-ans)) ans = sum;
            }
        }
        return ans;
    }
};