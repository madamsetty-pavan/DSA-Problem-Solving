class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        vector<vector<int>>ans;
        long long n=nums.size(),sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i+3<n;)
        {
            for(int j=i+1;j+2<n;)
	{
		int left=j+1,right=n-1;
		while(left<right)
		{
			sum = (long long) nums[i]+nums[j]+nums[left]+nums[right];
			if(sum==target)
			{
				ans.push_back({nums[i],nums[j],nums[left],nums[right]});
				left++;
				while(left<right && nums[left]==nums[left-1]) left++;
				right--;
				while(left<right && nums[right]==nums[right+1]) right--;
			}
			else if(sum>target)
			{
				right--;
			}
			else left++;
}
j++;
while(j<n && nums[j]==nums[j-1]) j++;
}
i++;
while(i<n && nums[i]==nums[i-1]) i++;
        }
return ans;
    }
};

