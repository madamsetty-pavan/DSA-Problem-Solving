class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int index = 0, sign = 1, notInt = 0;
        while(index<n) {
            if(s[index] =='-' || s[index] == '+') {
                if(notInt) return 0;
                if(s[index] == '-') sign = -1;
                notInt = 1;
                index++;
            } else if(s[index] == ' ') {
                if(notInt) { return 0;}
                index++;
            } else if(s[index]>='0' && s[index]<='9'){
                break;
            } else {
                return 0;
            }
        }
        int val = recurse(s, index, 0, n, sign);
        if(val == INT_MIN) return val;
        return sign * val;
    }
    
    int recurse(string&s, int index, long long number, int &stringSize, int &sign) {
        if(index == stringSize) return number;
        if(s[index] == ' ') return number;
        if(!(s[index]>='0' && s[index]<='9')) return number;
        // sign check
        if(sign == 1) {
            if(number>INT_MAX/10 || (number == INT_MAX/10 && s[index]>'7')) return INT_MAX;
        } else if(sign == -1) {
            if(number>INT_MAX/10 || (number == INT_MAX/10 && s[index]>'8')) return INT_MIN;
        }
        number = number *10 + (s[index]-'0');
        return recurse(s, index+1, number, stringSize, sign);
    }
};