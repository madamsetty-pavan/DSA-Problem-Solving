/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let ans = [], buffer = [];
    recurse(0);
    return ans;
    
    function recurse(index) {
        if(index==nums.length) {
            ans.push(buffer.slice());
            return;
        }
        buffer.push(nums[index]);
        recurse(index+1);
        buffer.pop();
        recurse(index+1);
    }
};