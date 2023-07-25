// Recursion with memo

#include <bits/stdc++.h> 
int recurse(int index, vector<int> &nums, vector<int>&dp) {
    if (index==0) {
        dp[index] = nums[0];
        return nums[0];
    }
    if (index<0) return 0;
    if(dp[index]!=-1) return dp[index];
    int  ans = recurse(index-2,nums,dp) + nums[index];
    ans = max(ans, recurse(index-1,nums,dp));
    return dp[index]=ans;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size(),-1);
    recurse(nums.size()-1,nums,dp);
    return dp[nums.size()-1];
}


// Without recursion bottom-up approach with space optimised

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int prev2 = 0, prev = nums[0], curr;
    for(int i=1;i<nums.size();i++) {
        curr = max(nums[i]+prev2, prev);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}





