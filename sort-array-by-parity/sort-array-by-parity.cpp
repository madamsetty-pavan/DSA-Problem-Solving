class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int j=0,k=A.size()-1;
        while(j<k)
        {
            while(j<k && A[j]%2==0) j++;
            while(j<k && A[k]%2!=0) k--;
            swap(A[j],A[k]);
        }
        return A;
    }
};