class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0, n = students.size(), m = mentors.size();
        vector<bool> mentorIsTaken(students.size(),0);
        recurse(students, mentors, 0, mentorIsTaken, ans, 0, n, m);
        return ans;
    }
    
    void recurse(vector<vector<int>>& students, vector<vector<int>>& mentors, int studentIndex, vector<bool>&mentorIsTaken, int &ans, int score, int &n, int &m) {
        if (studentIndex == n) {
            ans = max(ans, score);
            return;
        }
        for(int i=0;i<m;i++) {
            if(!mentorIsTaken[i]) {
                int tempScore = checkCommonScores(students[studentIndex], mentors[i]);
                mentorIsTaken[i] = true;
                recurse(students, mentors, studentIndex+1,  mentorIsTaken, ans, score + tempScore, n,m);
                mentorIsTaken[i] = false;
            }
        }
    }
    
    int checkCommonScores(vector<int>& studentScore, vector<int>& mentorScore) {
        int ans = 0, n = studentScore.size();
        for(int i=0;i<n;i++) {
            ans += (studentScore[i] == mentorScore[i]);
        }
        return ans;
    }
    
};