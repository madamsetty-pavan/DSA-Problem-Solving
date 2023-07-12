class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
				int n = nums.size(), left, right;
				long long sum = 0;
				for(int i=0;i+3<n;) {
					for(int j=i+1;j+2<n;) {
						left = j+1;
						right = n-1;
						while(left<right) {
							sum = (long long)nums[left] + nums[right] + nums[i] +nums[j];
							if(sum == target) {
								ans.push_back({nums[left],nums[right], nums[i], nums[j]});
								left++;
								right--;
								while(left<right && nums[left]==nums[left-1]) left++;
								while(left<right && nums[right]==nums[right+1]) right--;
							} else if(sum < target) left++;
							else right--;
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