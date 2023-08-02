#include <bits/stdc++.h> 
// Recursive solution
// int recurse(int index, vector<int>&weight, vector<int>&value, int maxWeight) {
// 	if(maxWeight <= 0) return 0;
// 	if(index==0) {
// 		if(maxWeight>=weight[index]) return value[index];
// 		else return 0;
// 	}
// 	int notTake = recurse(index-1,weight,value, maxWeight);
// 	int take = 0;
// 	if(weight[index]<=maxWeight) {
// 		take = recurse(index-1, weight, value, maxWeight-weight[index]) +value[index];
// 	}
// 	return max(take, notTake);
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// Write your code here
// 	return recurse(weight.size()-1,weight,value,maxWeight);
// }


// Recursive with memo

// int recurse(int index, vector<int>&weight, vector<int>&value, int maxWeight, vector<vector<int>> &dp) {
// 	if(maxWeight <= 0) return dp[index][maxWeight]=0;
// 	if(index==0) {
// 		if(maxWeight>=weight[index]) return dp[index][maxWeight]=value[index];
// 		else return dp[index][maxWeight]=0;
// 	}
// 	if(dp[index][maxWeight]!=-1) return dp[index][maxWeight];
// 	int notTake = recurse(index-1,weight,value, maxWeight,dp);
// 	int take = 0;
// 	if(weight[index]<=maxWeight) {
// 		take = recurse(index-1, weight, value, maxWeight-weight[index],dp) +value[index];
// 	}
// 	return dp[index][maxWeight]=max(take, notTake);
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// Write your code here
// 	vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));
// 	return recurse(weight.size()-1,weight,value,maxWeight,dp);
// }



// // Tabulation

// int knapsack(vector<int> weights, vector<int> value, int n, int maxWeight) 
// {
// 	vector<vector<int>> dp(n, vector<int>(maxWeight+1,0));

// 	for(int i = weights[0];i<=maxWeight;i++) dp[0][i] = value[0];

// 	for(int index = 1;index < weights.size();index++) {
// 		for(int weight = 0;weight <= maxWeight; weight++) {
// 			int notTake = dp[index-1][weight];
// 			int take = 0;
// 			if(weights[index] <= weight) {
// 				take = dp[index-1][weight-weights[index]] + value[index];
// 			}
// 			dp[index][weight] = max(take,notTake);
// 		}
// 	}
// 	return dp[weights.size()-1][maxWeight];
// }




// Tabulation - MORE space optimised 
// Fill from the right and use the same dp array for next iteration too
int knapsack(vector<int> weights, vector<int> value, int n, int maxWeight) 
{
	vector<int> dp(maxWeight+1,0);

	for(int i = weights[0];i<=maxWeight;i++) dp[i] = value[0];

	for(int index = 1;index < weights.size();index++) {
		for(int weight = maxWeight;weight >= 0; weight--) {
			int notTake = dp[weight];
			int take = 0;
			if(weights[index] <= weight) {
				take = dp[weight-weights[index]] + value[index];
			}
			dp[weight] = max(take,notTake);
		}
	}
	return dp[maxWeight];
}


// Tabulation - more space optimised
