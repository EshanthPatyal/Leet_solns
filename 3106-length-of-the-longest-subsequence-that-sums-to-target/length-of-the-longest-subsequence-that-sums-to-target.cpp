class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,INT_MIN));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(j>=nums[i-1]){
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j-nums[i-1]]);
                }
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
            // max(dp[i][target],nums)
        }
        return dp[n][target]>=0?dp[n][target]:-1;
    }
};