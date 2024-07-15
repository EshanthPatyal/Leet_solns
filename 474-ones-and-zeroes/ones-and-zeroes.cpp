class Solution {
public:
    int countones(string s){
        int out=0;
        for(auto it:s){
            out+=it-'0';
        }
        return out;
    }
    int recur(vector<string>&str,vector<vector<vector<int>>>&dp,int m,int n,int idx){
        if(idx==str.size())return 0;
        if(m<0 || n<0)return -1e5;
        if(dp[idx][m][n]!=-1)return dp[idx][m][n];
        int co=countones(str[idx]);
        int cz=str[idx].length()-co;
        int take=INT_MIN;
        if(cz<=m && co<=n){
            take=1+recur(str,dp,m-cz,n-co,idx+1);
        }
        return dp[idx][m][n]=max(take,recur(str,dp,m,n,idx+1));
    }
    int findMaxForm(vector<string>& str, int m, int n) {
        vector<vector<vector<int>>>   dp(str.size(),vector<vector<int>>
        (m+1,vector<int>(n+1,-1)));
        return recur(str,dp,m,n,0);
    }
};