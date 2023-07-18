/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let res = [], arr = [], index =0;

    function recur(arr, index, nums) {
        if(index==nums.length) { res.push(arr); return; }
        
        recur([...arr, nums[index]], index+1, nums);
        
        recur(arr, index+1, nums);
    }

    recur(arr,index, nums);
    return res;
};

