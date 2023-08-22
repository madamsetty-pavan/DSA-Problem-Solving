class Solution {
public:
    string convertToTitle(int columnNumber) {
        string dicti[26] =  {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        string ans = "";
        int x;
        while(columnNumber>0) {
            x = columnNumber%26;
            if(x==0) {
                x =26;
                columnNumber--;
            }
            ans += dicti[x-1];
            columnNumber /=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};