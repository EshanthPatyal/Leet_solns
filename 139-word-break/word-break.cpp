class Solution {
public:
    bool dfs(string s,vector<vector<string>>&v,int i,vector<int>&dp){
        if(i>=s.length())return 1;
        if(dp[i]!=-1)return dp[i]==1;
        int ne=s[i]-'a';
        for(auto it:v[ne]){
            int cur=it.size();
            if(cur+i-1>s.length())continue;
            if( it==s.substr(i,it.size()) && dfs(s,v,i+it.size(),dp)){
                dp[i]=1;
                return 1;
            }
        }
        dp[i]=0;
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> v(26);
        for(auto it:wordDict){
            v[it[0]-'a'].push_back(it);
        }
        queue<string>q;
        q.push("");
        int n=s.length();
        // map<string,int>mp;
        vector<int> dp(s.length(),-1);
        // dp[0]=1;
        return dfs(s,v,0,dp)==1;
    }
};