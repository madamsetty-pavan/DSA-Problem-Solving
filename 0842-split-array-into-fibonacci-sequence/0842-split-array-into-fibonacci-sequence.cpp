class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans, temp;
        int n = num.length();
        //cout<<n<<endl;
        vector<int> dp(n,-1);
        recurse(0, num, temp, ans, n, dp);
        return ans;
    }
    
    bool recurse(int index, string &num, vector<int>&temp, vector<int>&ans, int&n, vector<int>&dp) {
        // cout<<index<<endl;
        if(index == n) {
            // cout<<"came at n"<<endl;
            if(temp.size()>=3 && temp[temp.size()-3] + temp[temp.size()-2] == temp[temp.size()-1]) {
            ans = temp;
            return true;
            } else return false;
        }
        if(index == n-1) {
            // for(int i=0;i<temp.size();i++) {
            //     cout<<temp[i]<<" ";
            // }
            // cout<<endl;
            if(temp.size()>=3 && temp[temp.size()-1] + temp[temp.size()-2] == num[index]-'0') {
                temp.push_back(num[index]-'0');
                ans = temp;
                return true;
            } else return false;
        }
        string str = "";
        int number = 0;
        for(int i=index;i<n;i++) {
            if(number>INT_MAX/10 || (number ==INT_MAX/10 && num[i]>7-'0' )) return false; 
            str += num[i];
            // cout<<str<<endl;
            number = stoi(str);
            // if(number>INT_MAX/10 || (number ==INT_MAX/10 && num[i]>7-'0' )) return false; 
            // cout<<number<<endl;
            if(temp.size()>=2) {
                // cout<<i<<" came"<<endl;
                if(temp[temp.size()-1] >= INT_MAX - temp[temp.size()-2]) return dp[index]=false;
                int sum = temp[temp.size()-1] + temp[temp.size()-2];
                if(sum == number) {
                    temp.push_back(number);
                    // cout<<"true"<<endl;
                    if(recurse(i+1,num,temp, ans,n,dp)) return dp[index]=true;
                    temp.pop_back();
                } else if(sum<number) {
                    return  dp[index]=false;
                } else {
                    if(number==0) return  dp[index]=false;
                    else {
                        continue;
                    }
                }
            } else {
                temp.push_back(number);
                if(recurse(i+1,num,temp, ans,n,dp)) return  dp[index]=true;
                temp.pop_back();
            }
            
        }
        return dp[index]=false;
    }
};