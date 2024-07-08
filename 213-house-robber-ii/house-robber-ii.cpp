class Solution {
public:
    int helper(vector<int>& v,vector<int>& dp,int i,int n,int flag){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take_curr,dont_take_curr;
        if(i==n-1 && flag){
            take_curr=helper(v,dp,i+2,n,flag);
             dont_take_curr=helper(v,dp,i+1,n,flag);            
        }
        else{
            take_curr=v[i]+helper(v,dp,i+2,n,flag);
            dont_take_curr=helper(v,dp,i+1,n,flag);
        }
        return dp[i]=max(take_curr,dont_take_curr);
    }
    int rob(vector<int>& v) {
        int n=v.size();
        vector<int>dp1(n,0),dp2(n+1,0);
        if(n==1)return v[0];
        dp1[0]=0;
        dp1[1]=v[0];
        for(int i=1;i<n-1;i++){
            dp1[i+1]=max(dp1[i],v[i]+dp1[i-1]);
        }
        
        dp2[1]=0;
        dp2[2]=v[1];
        for(int i=2;i<n;i++){
            dp2[i+1]=max(dp2[i],v[i]+dp2[i-1]);
        }
        return max(dp1[n-1],dp2[n]);

        // return max(v[0]+helper(v,dp1,2,n,1),helper(v,dp2,1,n,0));
    }
};