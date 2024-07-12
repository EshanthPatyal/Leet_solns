class Solution {
public:
    bool dfs(string s,vector<vector<string>>&v,int i,vector<int>&dp){
        if(i>=s.length())return 1;
        if(dp[i]!=-1)return dp[i]==1;
        int ne=s[i]-'a';
        for(auto it:v[ne]){
            int cur=it.size();
            if(it==s || cur+i-1>s.length())continue;
            if( it==s.substr(i,it.size()) && dfs(s,v,i+it.size(),dp)){
                dp[i]=1;
                return 1;
            }
        }
        dp[i]=0;
        return 0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        vector<vector<string>> v(26);
        for(auto it:words){
            v[it[0]-'a'].push_back(it);
        }        
        for(int i=0;i<words.size();i++){
            vector<int> dp(words[i].length(),-1);
            if(dfs(words[i],v,0,dp)==true){
                ret.push_back(words[i]);
            }
        }
        return ret;
    }
};