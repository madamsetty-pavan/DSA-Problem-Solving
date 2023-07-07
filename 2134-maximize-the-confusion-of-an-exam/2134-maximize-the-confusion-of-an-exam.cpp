class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxAnswer(answerKey, k, 'T'), maxAnswer(answerKey, k, 'F'));
    }

    int maxAnswer(string answerKey, int k, char value) {
        int count =0, ans = 0, n = answerKey.size();
        for (int left=0, right=0;right<n;right++) {
            if(answerKey[right] == value) ans = max(ans, right-left+1);
            else {
                count++;
                while(count>k) {
                    if(answerKey[left] != value) {count--;}
                    left++;
                }
                ans = max(ans,right-left+1);
            }
        }
        return ans;
    }
};