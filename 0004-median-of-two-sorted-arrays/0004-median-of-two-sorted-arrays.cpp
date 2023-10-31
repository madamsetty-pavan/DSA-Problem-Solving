class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m) {
            return findMedianSortedArrays(nums2,nums1);
        }
        int left = 0, right = n, low = (n+m+1) >> 1, mid1 , mid2 , l1, l2, r1, r2;
        while(left <= right) {
            mid1 = (left + right) >> 1;
            mid2 = low - mid1;
            if(mid1-1>=0) l1 = nums1[mid1-1]; 
            else l1 = INT_MIN;
            
            if(mid2-1>=0) l2 = nums2[mid2-1];
            else l2 = INT_MIN;
            
            if(mid1<n) r1 = nums1[mid1];
            else r1 = INT_MAX; 
            
            if(mid2<m) r2 = nums2[mid2];
            else r2 = INT_MAX;

            if(l1<=r2 && l2<=r1) {
                break;
            }
            if(l1>r2) {
                right = mid1 - 1;
            } else left = mid1 + 1;
        }
        if((n+m) %2 !=0) return max(l1, l2);
        return ((double)max(l1, l2) + (double)min(r2, r1)) / 2.0;
    }
};