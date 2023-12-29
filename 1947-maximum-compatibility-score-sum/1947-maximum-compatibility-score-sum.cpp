class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        vector<bool> mentorIsTaken(students.size(),0);
        recurse(students, mentors, 0, mentorIsTaken, ans, 0);
        return ans;
    }
    
    void recurse(vector<vector<int>>& students, vector<vector<int>>& mentors, int studentIndex, vector<bool>&mentorIsTaken, int &ans, int score) {
        if(studentIndex == students.size()) {
            ans = max(ans, score);
            return;
        }
        for(int i=0;i<mentors.size();i++) {
            if(!mentorIsTaken[i]) {
                int tempScore = checkCommonScores(students[studentIndex], mentors[i]);
                mentorIsTaken[i] = true;
                recurse(students, mentors, studentIndex+1,  mentorIsTaken, ans, score + tempScore);
                mentorIsTaken[i] = false;
            }
        }
    }
    
    int checkCommonScores(vector<int>& studentScore, vector<int>& mentorScore) {
        int ans = 0;
        for(int i=0;i<studentScore.size();i++) {
            ans += (studentScore[i] == mentorScore[i]);
        }
        return ans;
    }
    
};