class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(),i = 0 ;
        while(i<n && s[i] == ' ') {
                i++;
        }
        int sign = 1;
        if(s[i]=='-' || s[i]=='+') {
            if(s[i]=='-') sign = -1;
            i++;
        }
        int ans = 0;
        while(i<n && s[i]>='0' && s[i]<='9') {
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]>'7')){
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            ans = ans *10 +(s[i++]-'0');
        }
        return ans*sign;
    }
};