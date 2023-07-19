/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const arr = [];
    recur(nums,0);
    
    function recur(nums,index) {
        if(index===nums.length) {
            arr.push(nums.slice());
            return;
        }
        for(let i=index;i<nums.length;i++) {
            [nums[index],nums[i]] = [nums[i],nums[index]];
            recur(nums,index+1);
            [nums[i],nums[index]] =  [nums[index],nums[i]];
        }
    }
    return arr;
};