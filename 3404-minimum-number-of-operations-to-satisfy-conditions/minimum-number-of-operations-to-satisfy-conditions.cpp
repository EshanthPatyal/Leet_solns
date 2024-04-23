class Solution {
public:
    int helper(vector<vector<int>>& v,vector<vector<int>>&dp,int idx,int prev,int col_size){
        if(idx<0){
            return 0;
        }
        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        int a=INT_MAX;
        for(int i=0;i<=9;i++){
            if(i!=prev){
                int t= col_size-v[idx][i] + helper(v,dp,idx-1,i,col_size);
                if(t<a){
                    a=t;
                }
            }
        }
        return dp[idx][prev]=a;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int c=grid[0].size();
        vector<vector<int>> v(c,vector<int> (11,0));
        vector<vector<int>> dp(c,vector<int>(11,-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                v[j][grid[i][j]]++;
            }
        }
        int out=INT_MAX;

        return helper(v,dp,c-1,10,grid.size());
    }
};