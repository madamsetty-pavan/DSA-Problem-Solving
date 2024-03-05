class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = nums.size()-1, ans = 0, right = left, sum = 0, target = nums[left];
        while(left>=0) {
            sum += nums[left];
            while((long long)(right-left+1)*target - sum > k) {
                sum -= nums[right--];
                if(right<0) return ans;
                target = nums[right];
            }
            ans = max(ans, (right-left+1));
            left--;
        }
        return ans;
    }
};