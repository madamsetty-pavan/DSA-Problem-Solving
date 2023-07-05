class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int right = nums.size()-1;
        for(int i=0;i<right;) {
            if(nums[i]%2!=0) {
                swap(nums[i],nums[right--]);
            } else i++;
        }
        return nums;
    }
};