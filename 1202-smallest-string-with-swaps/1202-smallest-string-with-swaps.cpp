class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> adjMatrix(n);
        for(auto &x:pairs) {
            adjMatrix[x[0]].push_back(x[1]);
            adjMatrix[x[1]].push_back(x[0]);
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<adjMatrix[i].size();j++) {
        //         cout<<adjMatrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++) {
            if(visited[i] == false) {
                vector<int> indices;
                string str = "";
                recurse(adjMatrix, indices, str,i, n, s, visited);
                //cout<<str<<endl;
                constructString(indices, str, s);
                //cout<<s<<endl;
            }
        }
        return s;
    }
    
    void constructString(vector<int> &indices, string &str, string &s) {
        sort(str.begin(),str.end());
        sort(indices.begin(),indices.end());
        for(int i=0;i<str.size();i++) {
            s[indices[i]] = str[i];
        }
    }
    
    void recurse(vector<vector<int>> &adjMatrix, vector<int> &indices, string &str, int index, int &n, string &s, vector<bool> &visited) {
        if(visited[index] == true) return;
        visited[index] = true;
        indices.push_back(index);
        str +=s[index];
        // cout<<str<<endl;
        for(int i=0;i<adjMatrix[index].size();i++) {
            if(visited[adjMatrix[index][i]] == false) {
                recurse(adjMatrix, indices, str, adjMatrix[index][i], n, s, visited);
            }
        }
    }
};