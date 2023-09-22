#include <bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    unordered_map<int,int> mp;
    mp[0] = 1;
    int count = 0, exor = 0, n= a.size();
    for(int i=0;i<n;i++) {
        exor ^= a[i];
        count += mp[exor^b];
        mp[exor]++;
    }
    return count;
}
