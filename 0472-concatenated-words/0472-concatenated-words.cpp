class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.size()==0) return {};
        if(words[0].size()==0) return {};
        vector<string> ans;
        unordered_set<string> st(words.begin(),words.end());
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(words[i].size()==0) continue;
            st.erase(words[i]);
            vector<int> visited(words[i].size(),-1);
            if(dfs(words[i],ans,st,0, visited))
            {
                ans.push_back(words[i]);
            }
            st.insert(words[i]);
        }
        return ans;
    }
    
    bool dfs(string &words, vector<string>& ans, unordered_set<string> &st,int index, vector<int>&visited)
    {
        int n=words.size();
        if(index==n) {
            return true;
        }
        if(visited[index] != -1) return visited[index];
        string str="";
        for(int i=index;i<n;i++)
        {
            str+=words[i];
            if(st.find(str)!=st.end())
            {
                if(dfs(words,ans,st,i+1, visited))
                {
                    return visited[index] = true;
                }
            }
        }
        return visited[index] = false;
    }
};