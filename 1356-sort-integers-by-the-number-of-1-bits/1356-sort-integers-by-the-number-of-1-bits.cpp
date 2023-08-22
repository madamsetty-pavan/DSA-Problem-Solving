class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), comp);
        return arr;
    }
    
    static bool comp(int &a , int &b) {
        int p = count1s(a);
        int q = count1s(b);
        if(p==q) return a<=b;
        return p<q;
    }
    
    static int count1s(int a){
        int count = 0;
        while(a>0) {
            a = a & (a-1);
            count++;
        }
        return count;
    }
};