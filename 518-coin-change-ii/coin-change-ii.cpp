class Solution {
public:
    int f(int i,int k,vector<int>& v, vector<vector<int>>& dp){
        if(i==0){
            if(k%v[i]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int not_take=f(i-1,k,v,dp);
        int take=0;
        if(v[i]<=k){
            take=f(i,k-v[i],v,dp);
        }
        return dp[i][k]=(not_take+take);
    }
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        // int a= f(coins.size()-1,amount,coins,dp);
       vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        // int a= f(coins.size()-1,amount,coins,dp);
        int n=coins.size();
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int k=1;k<=amount;k++){
                dp[i][k]=dp[i-1][k];
                int l=k;
                while(l>=coins[i-1]){
                    // dp[i][k]=(dp[i][k]+(k/coins[i-1])+dp[i-1][k-coins[i-1]]);
                    l-=coins[i-1];
                    dp[i][k]+=dp[i-1][l];
                }
            }
        }
        int a=dp[n][amount]; 
        return a;        
    }
};