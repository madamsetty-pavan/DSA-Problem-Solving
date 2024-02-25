class Solution {
public:
    string reorganizeString(string s) {
        if(s.size()==0) return "";
        vector<int> count(26,0);
        int n=s.size();
        string ans=s;
        for(auto x:s)
        {
            count[x-'a']++;
        }
        int max=0;
        for(int i=1;i<26;i++)
        {
            if(count[i]>count[max])
            {
                max=i;
            }
        }
        if(count[max]>((s.size()+1)/2)) return "";
        int i=0;
        while(count[max]>0)
        {
            ans[i]=max+'a';
            i+=2;
            count[max]--;
        }
        int j=0;
        while(j<26)
        {
            while(count[j]>0)
            {
                if(i>=s.size()) i=1;
                ans[i]=j+'a';
                i+=2;
                count[j]--;
            }
           j++; 
        }
        return ans;
    }
};