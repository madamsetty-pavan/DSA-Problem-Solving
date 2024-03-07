
class Solution {
public:
    string simplifyPath(string path) {
         std::istringstream iss(path);
        std::string tmpS;
        
        std::vector<std::string> tmpVec;
        string ans="",temp;
        vector<string> st;
        for(auto x:path)
        {
            if(x=='/')
            {
                if(temp=="..")
                {
                    if(st.size()) st.pop_back(); 
                }
                else if(temp!="." && temp!="")
                {
                   st.push_back(temp);
                }
                temp="";
            }
            else
                temp+=x;
        }
        if(temp==".."){
            if(st.size()) st.pop_back();
        }
        else if(temp!="." && temp[0]!='/'&&temp!="") st.push_back(temp);
       for(auto x:st)
       {
           ans += '/' + x ;
       }
        if(!ans.size()) return "/";
        return ans;
    }
};