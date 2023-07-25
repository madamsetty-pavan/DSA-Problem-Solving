#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev2 = 0, prev = abs(heights[1]-heights[0]), curr = prev2;
    
    for(int i=2;i<n;i++) {
        curr = min(prev + abs(heights[i]-heights[i-1]), prev2 + abs(heights[i]-heights[i-2]));
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
