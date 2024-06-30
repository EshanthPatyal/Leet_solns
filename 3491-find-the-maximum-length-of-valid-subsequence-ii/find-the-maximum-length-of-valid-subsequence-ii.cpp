class Solution {
public:

    int maximumLength(vector<int>& nums, int k) {
        // m=k;
        int ans=1;
        vector<vector<int>> dp(k,vector<int>(k,0));
        int n=nums.size();
                // if(i==0){
                // }
        for(int i=0;i<n;i++){
            int curr=nums[i]%k;
            for(int j=0;j<k;j++){
                int prev=(j-curr+k)%k;
                dp[curr][j]=max(dp[curr][j],1+dp[prev][j]);
                ans=max(ans,dp[curr][j]);
            }
        }

        return ans;
        
    }
};