int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i=1;i<n;i++) {
        dp[i] = INT_MAX;
        for(int j=1;j<=k;j++) {
            if(i-j<0) break;
            dp[i] = min(dp[i], abs(height[i]-height[i-j]) + dp[i-j]);
        }
    }
    return dp[n-1];
}
