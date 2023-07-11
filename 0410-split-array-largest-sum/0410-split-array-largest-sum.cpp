class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0, mid;
        for(auto x:nums) {
            left = max(left,x);
            right += x; 
        }
        while(left<right) {
            mid = left + (right-left)/2;
            if(isFeasible(nums, mid, k)) right = mid;
            else left = mid+1;
        }
        return left;
    }

    bool isFeasible(vector<int>& nums, int total, int k) {
        int group = 1, sum =0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(sum>total) {
                sum = nums[i];
                group++;
                if(group>k) return false;
            }
        }
        return true;
    }
};