/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    let ans = [], flag = 1;
    for(let i=0;i<asteroids.length;i++) {
        if(ans.length && ans.slice(-1)>0 && asteroids[i]<0) {
            flag = 1;
            while(ans.length && ans.slice(-1)>0 && asteroids[i]<0) {
            if(Math.abs(ans.slice(-1))<Math.abs(asteroids[i])) {
                ans.pop();
            } else if(Math.abs(ans.slice(-1))===Math.abs(asteroids[i])) {
                flag=0;
                ans.pop();
                break;
            } else {
                flag=0;
                break;
               }
        }
            if(flag) ans.push(asteroids[i]);
        } else {
            ans.push(asteroids[i]);
        }
    }
    return ans;
};