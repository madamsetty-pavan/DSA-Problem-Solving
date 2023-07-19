/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    let ans = [], temp = [];
    nums.sort();
    recurse(0);
    return ans;
    
    function recurse(index) {
        ans.push(temp.slice());
        for(let i = index; i < nums.length; i++) {
            if(i!=index && nums[i]===nums[i-1]) continue;
            temp.push(nums[i]);
            recurse(i+1);
            temp.pop();
        }
    }
    
};