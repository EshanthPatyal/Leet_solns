class Solution {
public:
    bool validPartition(vector<int>& v) {
        vector<bool> dp(v.size()+1,false);
        dp[0]=true;
        dp[1]=false;
        int n=v.size();
        for(int i=2;i<=v.size();i++){
            if(v[i-1]==v[i-2]){
                dp[i]=dp[i]||dp[i-2];
            }
            if(i>=3){
                if(v[i-1]==v[i-2] && v[i-1]==v[i-3]){
                    dp[i]=dp[i]||dp[i-3];
                }
                if(v[i-1]==v[i-2]+1 && v[i-1]==v[i-3]+2){
                    dp[i]=dp[i]||dp[i-3];
                }
            }
        }
        return dp[n];
    }
};