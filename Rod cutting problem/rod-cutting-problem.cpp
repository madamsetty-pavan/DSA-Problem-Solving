int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++) {
        if(i%weight[0]==0) dp[0][i] = ((i/weight[0])*profit[0]);
    }
    for(int index = 1; index<n; index++) {
        for(int j =0;j<=w;j++) {
            int notTake = dp[index-1][j];
            int take = 0;
            if(weight[index]<=j) {
                take = profit[index]+dp[index][j-weight[index]];
            }
            dp[index][j] = max(take,notTake);
        }
    }
    return dp[n-1][w];
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> nums;
	for(int i=1;i<=n;i++) nums.push_back(i);
	return unboundedKnapsack(n,n,price,nums);
}
