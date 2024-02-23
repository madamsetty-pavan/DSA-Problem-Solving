class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        return (checkIfIsomorphic(s,t,n) && checkIfIsomorphic(t,s,n));
    }
    bool checkIfIsomorphic(string &s, string &t, int &n) {
        unordered_map<char, char> mp;
        for(int i=0; i<n; i++) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = t[i];
            } else if(mp[s[i]] != t[i]) return false;
        }
        return true;
    }
};