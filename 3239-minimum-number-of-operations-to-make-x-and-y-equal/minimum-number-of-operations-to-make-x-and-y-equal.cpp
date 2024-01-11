class Solution {
public:
    int helper(int x,int y, vector<int>& dp, int n){
        if(y>=x){
            return y-x;
        }
        if(x<=0 || x>1e4 ) return INT_MAX;
        if(dp[x]!=INT_MAX){
            return dp[x];
        }
        int elev=INT_MAX,fic=INT_MAX,dec=INT_MAX;
        if(x%11==0){
            elev=1+helper(x/11,y,dp,n);
        }
        else{
            elev=min(x%11+helper(x/11,y,dp,n)+1,(11-x%11)+helper(1+ x/11,y,dp,n)+1);
        }
        if(x%5==0){
            fic=1+helper(x/5,y,dp,n);
        }
        else{
            fic=min(x%5+helper(x/5,y,dp,n)+1,(5-x%5)+helper(1+ x/5,y,dp,n)+1);
        }              
        dec=1+helper(x-1,y,dp,n);
        dp[x]=min(dec,min(elev,fic));
        return dp[x];
        
    }
        
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> dp(10000+5,INT_MAX);
        
        return helper(x,y,dp,x-y);
        

    }
};