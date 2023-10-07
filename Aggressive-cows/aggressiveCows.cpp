#include<bits/stdc++.h>
bool isFeasible(vector<int>&stalls, int mid, int k) {
    int k1 = k-1, prev = 0;
    int n = stalls.size();
    for(int i=1;i<n;i++) {
        if(k1 == 0) break;
        if(stalls[i]-stalls[prev]>=mid) {
          k1--;
          prev = i;  
        } 
    }
    return (k1==0);
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int left = 1, right = stalls[stalls.size()-1]-stalls[0], mid;
    while(left<=right) {
        mid = left + (right-left)/2;
        if(isFeasible(stalls,mid,k)) left = mid+1;
        else right = mid -1;
    }
    // cout<<left <<" "<<right<<endl;
    return right;
}


