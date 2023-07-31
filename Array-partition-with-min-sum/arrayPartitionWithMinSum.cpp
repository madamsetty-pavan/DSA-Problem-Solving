// The recursion solution of partition sum won't work for this.
// Since the table is made true in the next recursion call

int minSubsetSumDifference(vector<int>& nums, int n)
{
	// Write your code here.
        int sum = 0;
        for(auto x:nums) {
            sum += x;
        }
        vector<int> prev(sum+1,0), temp(sum+1,0);
        prev[0] = 1;
        if(nums[0]<=sum) temp[nums[0]] = 1;
        for(int index = 1;index<nums.size();index++) {
            for(int target = 0;target<=sum;target++) {
                bool take = false;
                if(target>=nums[index]) {
                    take = prev[target-nums[index]];
                }
                bool notTake = prev[target];
                temp[target] = take || notTake;
            }
            prev = temp;
        }
        int ans = INT_MAX;
        for(int i=1;i<sum;i++) {
            if(prev[i]==1) {
                //cout<<i<<" "<<abs(sum-2*i)<<endl;
                if(ans>abs(sum-2*i)) {
                    ans = abs(sum - 2*i);
                    // cout<<ans<<endl;
                }
                // ans = min(ans, abs(sum-2*i));
            }
            // cout<<ans<<endl;
        }
        // cout<<ans<<endl;
        return ans;
}

 
