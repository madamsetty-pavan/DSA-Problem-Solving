class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> forbiddenSet(forbidden.begin(), forbidden.end());
        int maxLen = 0;
        int start = 0, end = 0, n = word.length();

        while (end < n) {
            for (int len = 1; len <= 10 && (end - len + 1) >= start; ++len) {
                // Check if the substring ending at 'end' with length 'len' is forbidden
                if (forbiddenSet.find(word.substr(end - len + 1, len)) != forbiddenSet.end()) {
                    // Move 'start' to exclude the forbidden substring
                    start = end - len + 2;
                    break;
                }
            }
            // Update the maximum length of the valid substring
            maxLen = max(maxLen, end - start + 1);
            // Move 'end' to explore the next character
            ++end;
        }
        return maxLen;
    }
};