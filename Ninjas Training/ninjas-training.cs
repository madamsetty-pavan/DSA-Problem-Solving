#include<bits/stdc++.h>

// Recursive solution
int recurse(int index,  int prev, vector<vector<int>>&points) {
    int ans = INT_MIN;
    if(index == 0){ 
        for(int choices = 0; choices<3; choices++) {
            if(choices!=prev) {
                ans = max(ans, points[index][choices]);
            }
        }
        return ans;
    }
    for(int choices = 0; choices<3; choices++) {
        if(choices != prev) {
            ans = max(ans, points[index][choices] + recurse(index-1,choices, points));
        }
    }
    return ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return recurse(n-1, 3, points);

}

// Recursive with memoziation

int recurse(int index,  int prev, vector<vector<int>>&points,vector<vector<int>>& dp ) {
    if(dp[index][prev]!=-1) return dp[index][prev];
    int ans = INT_MIN;
    if(index == 0){ 
        for(int choices = 0; choices<3; choices++) {
            if(choices!=prev) {
                ans = max(ans, points[index][choices]);
            }
        }
        return dp[index][prev]=ans;
    }
    for(int choices = 0; choices<3; choices++) {
        if(choices != prev) {
            ans = max(ans, points[index][choices] + recurse(index-1,choices, points, dp));
        }
    }
    return dp[index][prev] =  ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return recurse(n-1, 3, points,dp);
}

// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4,-1));

    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1],points[0][2]));

    for(int index=1;index<n;index++) {
        for(int prev=0;prev<4;prev++) {
            int ans = INT_MIN;
            for(int choices=0;choices<3;choices++) {
                if(choices != prev) {
                    ans = max(ans, points[index][choices] + dp[index-1][choices]);
                }
            }
        dp[index][prev]  = ans;
        }
    }
    return dp[n-1][3];
}

// Tabulation with space optimised
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> dp(4,-1), temp(4,-1);

    dp[0] = max(points[0][1],points[0][2]);
    dp[1] = max(points[0][0],points[0][2]);
    dp[2] = max(points[0][0],points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1],points[0][2]));

    for(int index=1;index<n;index++) {
        for(int prev=0;prev<4;prev++) {
            int ans = INT_MIN;
            for(int choices=0;choices<3;choices++) {
                if(choices != prev) {
                    ans = max(ans, points[index][choices] + dp[choices]);
                }
            }
        temp[prev]  = ans;
        }
        dp = temp;
    }
    return dp[3];
}
