class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        stack<int> st;
        int ans=0,currnumber=0,top;
        char symbol='+';
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i])) currnumber=currnumber * 10 + (s[i]-'0');
            if(!isdigit(s[i]) && !iswspace(s[i]) || i==n-1)
               {
                   if(symbol=='-')
                   {
                       st.push(-currnumber);
                   }
                   else if(symbol=='+')
                   {
                       st.push(currnumber);
                   }
                   else if(symbol=='*')
                   {
                       top=st.top();
                       st.pop();
                       st.push(currnumber * top);
                   }
                   else if(symbol=='/')
                   {
                       top=st.top();
                       st.pop();
                       st.push(top / currnumber);
                   }
                     currnumber=0;
                     symbol=s[i];
               }
             
        }
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};