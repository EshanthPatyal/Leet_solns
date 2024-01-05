class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);

        int m=1;
        for( int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    
                    dp[i]=dp[j]+1;
                    m=max(dp[i],m);
                }
            }

        }
        vector<int> v;
        for(int i=nums.size()-1;i>0;i--){
            if(dp[i]!=dp[i-1]){
                v.push_back(nums[i]);
            }
            if(dp[i]==1){
                v.push_back(nums[i]);
                break;
            }
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        return m;
    }
};