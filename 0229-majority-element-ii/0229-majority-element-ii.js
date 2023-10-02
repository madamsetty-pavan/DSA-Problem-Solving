/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    var el1 = 100000, el2 = 100000, cnt1 = 0, cnt2 = 0, n = nums.length;
    for(var i=0;i<n;i++) {
        if(cnt1 == 0 && nums[i] !=el2) {
            cnt1 = 1;
            el1= nums[i];
        }
        else if(cnt2 ==0 && nums[i] != el1) {
            cnt2 = 1;
            el2 = nums[i];
        } else if(nums[i] == el1) {
            cnt1++;
        } else if(nums[i] == el2) {
            cnt2++; 
        } else {
            cnt1 --;
            cnt2 --;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for(var i=0;i<n;i++) {
        if(nums[i] == el1) cnt1++;
        if(nums[i] == el2) cnt2++;
    }
    var ans = [];
    if(cnt1 > Math.floor(n/3)) ans.push(el1);
    if(cnt2 > Math.floor(n/3)) ans.push(el2);
    return ans;
};