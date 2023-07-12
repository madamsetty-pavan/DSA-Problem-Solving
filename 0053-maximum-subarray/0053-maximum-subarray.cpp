class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum =0, ans = INT_MIN, start = 0, end;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            if(sum<nums[i])  { sum = nums[i]; start =i;}
            if(ans<=sum) {
                ans = sum;
                end = i;
            }
        }
        cout<<start<<" "<<end<<" "<<endl;
        return ans;
    }

};