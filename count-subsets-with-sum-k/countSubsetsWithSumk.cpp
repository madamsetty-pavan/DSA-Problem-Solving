// Recursive solution

int recurse(vector<int>&arr, int target, int index) {
	if(target==0) return 1;
	if(index==0)  {
		if(arr[index] == target) return 1;
		else return 0;
	}
	if(index<0) return 0;
	int notTake = recurse(arr,target,index-1);
	int take = 0;
	if(target>=arr[index]) {
		take = recurse(arr,target-arr[index],index-1);
	}
	return (take + notTake);
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	return recurse(arr,k,arr.size()-1);
}


// Recursive solution with memo
int modulo = 1e9 +7;
int recurse(vector<int>&arr, int target, int index, vector<vector<int>>&dp) {
	if(target==0) return dp[index][target] = 1;
	if(index==0)  {
		if(arr[index] == target) return dp[index][target] = 1;
		else return dp[index][target] = 0;
	}
	if(dp[index][target]!=-1) return dp[index][target];
	int notTake = recurse(arr,target,index-1,dp);
	int take = 0;
	if(target>=arr[index]) {
		take = recurse(arr,target-arr[index],index-1,dp);
	}
	return dp[index][target] = (take + notTake)%modulo;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	vector<vector<int>> dp(arr.size(), vector<int>(k+1,-1));
	return recurse(arr,k,arr.size()-1,dp);
}


// Tabulation
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int modulo = 1e9 +7;
	vector<vector<int>> dp(arr.size(), vector<int>(k+1,0));
	for(int i=0;i<arr.size();i++) {
		dp[i][0] = 1;
	}
	if(arr[0]<=k) dp[0][arr[0]] = 1;
	for(int i = 1;i<arr.size();i++) {
		for(int target = 0;target<=k; target++) {
			int notTake = dp[i-1][target];
			int take = 0;
			if(target>=arr[i]) {
				take = dp[i-1][target-arr[i]];
			}
			dp[i][target] = (take + notTake)%modulo;
		}
	}
	return dp[arr.size()-1][k];
}

// Tabulation with space optmised
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int modulo = 1e9 +7;
	vector<int> prev(k+1,0), temp(k+1,0);
	prev[0] = 1;
	if(arr[0]<=k) prev[arr[0]] = 1;
	for(int i = 1;i<arr.size();i++) {
		for(int target = 0;target<=k; target++) {
			int notTake = prev[target];
			int take = 0;
			if(target>=arr[i]) {
				take = prev[target-arr[i]];
			}
			temp[target] = (take + notTake)%modulo;
		}
		prev = temp;
	}
	return prev[k];
}

