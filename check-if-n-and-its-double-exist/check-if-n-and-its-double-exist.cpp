class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<double,int> mp;
        for(int i= 0;i<arr.size();i++) {
           double division = (double) arr[i]/2;
            if( (mp.find(division) != mp.end() && mp[division]!=i)  ||
                (mp.find(arr[i]*2) != mp.end() && mp[arr[i]*2]!=i) )  {
               
                return true;
            }
            mp[arr[i]] = i;
        }
        return false;
    }
};