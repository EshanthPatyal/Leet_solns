class Solution {
public:
    // int s1=0,s2=0;
long long recur(vector<vector<long long>>&dp,vector<int>&v,int i,int j,int f){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=LLONG_MAX)return dp[i][j];
    if(f==1){
        long long a=v[i]+recur(dp,v,i+1,j,2);
        a=max(a,v[j]+recur(dp,v,i,j-1,2));
        return dp[i][j]=a;
    }
    else{
        long long a=recur(dp,v,i+1,j,1)-v[i];
        a=min(a,recur(dp,v,i,j-1,1)-v[j]);  
        // s2+=a;
        return dp[i][j]=a;
    }
    
}
    // return a;

    bool predictTheWinner(vector<int>& nums) {
vector<vector<long long>> dp(100,vector<long long>(100,LLONG_MAX));

        return (recur(dp,nums,0,nums.size()-1,1)>=0);
    }
};