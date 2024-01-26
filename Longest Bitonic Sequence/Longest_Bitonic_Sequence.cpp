int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// Write your code here.
	vector<int> dpLIS(n,1), dpDIS(n,1);
	for(int i=0;i<n;i++) {
		for(int prev = 0; prev<i;prev++) {
			if(arr[i] > arr[prev]) {
				if(dpLIS[i] < 1 + dpLIS[prev]) {
					dpLIS[i] = 1 + dpLIS[prev];
				}
			}
		}
	}

	for(int i=n-1;i>=0;i--) {
		for(int prev = i+1; prev<n;prev++) {
			if(arr[i] > arr[prev]) {
				if(dpDIS[i] < 1 + dpDIS[prev]) {
					dpDIS[i] = 1 + dpDIS[prev];
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans = max(dpLIS[i] + dpDIS[i] -1, ans);
	}
	return ans;
}
