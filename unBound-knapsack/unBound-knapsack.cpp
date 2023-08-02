// Recursive soltion
int recurse(vector<int>&profit, vector<int>&weight, int index, int w) {
    if(index==0) {
        if(w%weight[0]==0) return (w/weight[0])*profit[0];
        return 0;
    }
    int notTake = recurse(profit,weight,index-1,w);
    int take = 0;
    if(weight[index]<=w) {
        take = recurse(profit,weight,index,w-weight[index]) + profit[index];
    }
    return max(take,notTake);
}


// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    return recurse(profit, weight, n-1, w);
}

// Recursive sol with memo
int recurse(vector<int>&profit, vector<int>&weight, int index, int w, vector<vector<int>> &dp) {
    if(index==0) {
        if(w%weight[0]==0) return dp[index][w]=((w/weight[0])*profit[0]);
        return dp[index][w]=0;
    }
    if(dp[index][w]!=-1) return dp[index][w];
    int notTake = recurse(profit,weight,index-1,w,dp);
    int take = 0;
    if(weight[index]<=w) {
        take = recurse(profit,weight,index,w-weight[index],dp) + profit[index];
    }
    return dp[index][w]=max(take,notTake);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return recurse(profit, weight, n-1, w,dp);
}

// Tabulation with space optimised
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


