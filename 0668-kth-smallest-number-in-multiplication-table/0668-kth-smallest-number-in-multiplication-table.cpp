class Solution {
public:
    
    bool enough(int ans,int m,int n,int k)
    {
        int count=0;
        for(int i=1;i<=m;i++)
        {
            count+=min(ans/i,n);
        }
        return count>=k;
    }
    
    
    int findKthNumber(int m, int n, int k) {
        int low=1,high=m*n,mid;
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(enough(mid,m,n,k))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};