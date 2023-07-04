class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), j=n-1,i;
        for( i=0;i<=j;) {
            if(nums[i]==val) {
                swap(nums[i],nums[j--]);         
            } else i++;
        }
        return i;
    }
};