//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string temp = "";
        recurse(m,n,temp,0,0,ans);
        return ans;
    }
    
    void recurse(vector<vector<int>> &m, int n, string temp,int x, int y, vector<string> &ans) {
        if(x>=n || y>=n || x<0 || y<0) return;
        if(m[x][y]==0 || m[x][y]==-1) return;
        
        if(x==n-1 && y==n-1) {
            ans.push_back(temp);
            return;
        }
        
        
        m[x][y] = -1;
        //left
        temp+="L";
        recurse(m,n,temp,x,y-1,ans);
        temp.pop_back();
        
        //right
        temp+="R";
        recurse(m,n,temp,x,y+1,ans);
        temp.pop_back();
        
        //up
        temp+="U";
        recurse(m,n,temp,x-1,y,ans);
        temp.pop_back();
        
        //down
        temp+="D";
        recurse(m,n,temp,x+1,y,ans);
        temp.pop_back();
        
        m[x][y] = 1;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends