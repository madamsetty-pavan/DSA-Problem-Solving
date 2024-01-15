vector<int> printingLongestIncreasingSubsequence(vector<int> &arr, int n) {
	vector<int> dp(n,1), ans, hash(n,-1);
	int ansIndex=0;
	for(int i =0;i<n;i++) {
		for(int prev = 0;prev<i;prev++) {
			if(arr[prev] < arr[i]) {
				if(dp[i] < 1+dp[prev]) {
					dp[i] = 1 + dp[prev];
					hash[i] = prev;
				}
			}
		}
		if(dp[ansIndex] < dp[i]) {
			ansIndex = i;
		}
	}
	int count = dp[ansIndex];
	while(ans.size()<count) {
		ans.push_back(arr[ansIndex]);
		ansIndex = hash[ansIndex];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
