class Solution {
public:
    int recur(vector<int>&dp,string s,int i){
        if(i==s.length())return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return 0;

        dp[i]=recur(dp,s,i+1);
        if(i+1<s.length() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')) ){
            dp[i]+=recur(dp,s,i+2);
        }
        return dp[i];
    }
    int numDecodings(string s) {
        // return 1;
        int n=s.length();
        vector<int> dp(n,-1);
        // dp[0]=1;
        return recur(dp,s,0);

    }
};