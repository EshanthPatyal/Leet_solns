class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int m=p.size();
        int n=p[0].size();
        // cout<<m<<": "<<n;
        vector<vector<long long>> dp(m,vector<long long> (n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=p[0][j];
        }
        for(int i=1;i<m;i++){
            long long curr=-100;

            for(int j=0;j<n;j++){
                if(j>0)curr--;
                if(curr<dp[i-1][j]){
                    curr=dp[i-1][j];
                }
                dp[i][j]=max(dp[i][j],curr+p[i][j]);
            }
            curr=-100;

            for(int j=n-1;j>=0;j--){
                if(j<n-1)curr--;
                if(curr<dp[i-1][j]){
                    curr=dp[i-1][j];
                }
                dp[i][j]=max(dp[i][j],curr+p[i][j]);
            }
        }
        // cout<<endl;
        long long ret=LLONG_MIN;
        for(auto it:dp[m-1]){
            // cout<<it<<" ";
            ret=max(ret,it);
        }
        return ret;

    }
};