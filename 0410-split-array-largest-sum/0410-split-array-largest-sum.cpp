class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = INT_MIN, right = 0, mid;
        for (auto &x:nums) {
            left = max(left,x);
            right += x;
        }
        while(left<right) {
            mid = left + (right-left) /2;
            if(isFeasible(nums,mid,k)) {
                right = mid;
            } else left = mid + 1;
        }
        return left;
    }
    
    bool isFeasible(vector<int>&nums,  int mid, int &k) {
        int sum = 0, splitsCount = 1;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if (sum > mid) {
                splitsCount++;
                if(splitsCount>k) return false;
                sum = nums[i];
            }
        }
        return true;
    }
};