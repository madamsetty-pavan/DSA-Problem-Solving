// Recursion with Memo

int recurse(int index, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(index<0) return 0;
    if(dp[index][last]!= -1) return dp[index][last];
    int maxi = 0;
    for(int task =0; task<3; task++) {
        if(task != last) {
            maxi = max(maxi, points[index][task]+recurse(index-1,task,points,dp));
        }
    }
    return dp[index][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return recurse(n-1,3,points,dp);
}


// Tabluzation

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));

    for(int i = 0;i<3;i++) {
        int maxi = 0;
        for(int task=0; task < 3; task++) {
            if(i != task) {
                maxi = max(maxi, points[0][task]);
            }
        }
        dp[0][i] = maxi;
    }

    for(int day=1;day<n;day++) {
        for(int last=0;last<4;last++) {
            for(int task =0; task<3; task++) {
                if(task != last) {
                    dp[day][last] = max(dp[day][last], points[day][task]+dp[day-1][task]);
            }
            }
        }
    }
    return dp[n-1][3];
}



// Space optimised
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][1],points[0][0]);
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++) {
        vector<int>temp(4,0);
        for(int last=0;last<4;last++) {
            for(int task =0; task<3; task++) {
                if(task != last) {
                temp[last] = max(temp[last], points[day][task]+prev[task]);
            }
            }
        }
        prev = temp;
    }
    return prev[3];
}
