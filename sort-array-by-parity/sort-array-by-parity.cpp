class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, n = nums.size() ,right = n-1;
        for(int i=0;i<right;) {
            if(nums[i]%2!=0) {
                swap(nums[i],nums[right--]);
            } else i++;
        }
        return nums;
    }
};