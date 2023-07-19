/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let ans = [], temp = [];
    recurse(0,0);
    return ans;
    
    function recurse(index, sum) {
        if(index >= candidates.length || sum>=target) {
            if(sum===target) ans.push(temp.slice()); 
            return;
        }
        temp.push(candidates[index]);
        recurse(index,sum+candidates[index]);
        temp.pop();
        recurse(index+1,sum);
    }
};