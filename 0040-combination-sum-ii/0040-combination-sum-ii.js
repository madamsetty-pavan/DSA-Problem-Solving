/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    candidates.sort();
    let ans = [], temp = [];
    recur(0,0);
    return ans;
    
    function recur(index,sum) {
        console.log(index);
        if(sum>=target) {
            if(sum===target) ans.push(temp.slice());
            return;
        }
        for(let i=index;i<candidates.length;i++) {
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            temp.push(candidates[i]);
            recur(i+1,sum+candidates[i]);
            temp.pop();
        }
    }
    
};