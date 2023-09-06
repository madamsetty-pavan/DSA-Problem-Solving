class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, left = 0, n = chars.size(), count =0;
        while(i<n) {
            if(i+1<n && chars[i]==chars[i+1]) {
                count = 1;
                while(i+1<n && chars[i] == chars[i+1]){
                    count++;
                    i++;
                }
                append(chars, chars[i++], left, count);
            } else append(chars,chars[i++], left, 0);
        }
        return left;
    }
    
    void append(vector<char>&chars, char ch, int &left, int count) {
        if(count==0) {
            chars[left++] = ch;
            return;
        }
        chars[left++]= ch;
        string countStr = to_string(count);
        for(int i=0;i<countStr.size();i++) {
            chars[left++] = countStr[i];
        }
    }
    
};