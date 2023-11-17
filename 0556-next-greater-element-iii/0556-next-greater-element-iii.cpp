class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> temp;
        while(n>0) {
            temp.push_back(n%10);
            n = n/10;
        }
        reverse(temp.begin(), temp.end());
        int i = temp.size()-2;
        while(i>=0) {
            if(temp[i]<temp[i+1]) break;
            i--;
        }
        if(i<0) return -1;
        int j = i+1, n1 = temp.size(), leastIndex = j, leastNo = temp[j];
        while(j<n1) {
            if(temp[j]>temp[i]) {
                if(leastNo > temp[j]) {
                    leastIndex = j;
                    leastNo = temp[j];
                }
            }
            j++;
        }
        swap(temp[i], temp[leastIndex]);
        sort(temp.begin()+i+1, temp.end());
        int ans = 0;
        for(int i=0; i< n1; i++) {
            if((ans == INT_MAX/10 && temp[i]>7) || ans>INT_MAX/10) return -1;
            ans = ans *10 + temp[i];
        }
        return ans;
    }
};