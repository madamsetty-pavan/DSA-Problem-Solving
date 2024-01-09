string findLCS(int n, int m,string &text1, string &text2){
	// Write your code here.
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			if(text1[i-1] == text2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}  else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	string str ="";
	int i = n, j = m;
	while(str.size()<dp[n][m]){
		if(text1[i-1] == text2[j-1]) {
			str += text1[i-1];
			i--;
			j--;
		} else {
			if(dp[i-1][j]>=dp[i][j-1]) {
				i--;
			} else j--;
		}
	}
	reverse(str.begin(), str.end());
	return str;
}
