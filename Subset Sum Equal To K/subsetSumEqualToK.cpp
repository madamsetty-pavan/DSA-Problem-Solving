// #include <bits/stdc++.h> 

// bool recurse(int index, int j, vector<int>&arr, vector<vector<int>>&dp) {
//     if(j==0) return dp[index][j]=true;
//     if(index == 0)
//     {
//         if(arr[0] == j) return dp[index][j]=true;
//         else return dp[index][j]=false;
//     } 
//     if(dp[index][j]!= -1) return dp[index][j];
//     bool notTake = recurse(index-1, j, arr, dp);
//     bool take = false;
//     if(arr[index]<=j) {
//         take = recurse(index-1,j-arr[index], arr, dp);
//     }
//     return dp[index][j]=(take || notTake);
// }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1,0), temp(k+1,0);
    prev[0] = temp[0] = 1;
    cout<<arr[0]<<" "<<prev.capacity()<<" "<<prev.size()<<endl;
    prev[arr[0]] = 1;
    cout<<prev[0]<<endl;
    for(int index=1;index<n;index++) {
        for(int j=1;j<=k;j++) {
            bool notTake = prev[j];
            bool take = false;
            if(arr[index]<=j) 
                take = prev[j-arr[index]];
            temp[j] = take || notTake;
        }
        prev = temp;
    }
    return prev[k];
}
