class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp =nums;
        set<pair<int,int>> s;
        int out=INT_MIN;
        for(int i=0;i<k;i++){
            dp[i]=nums[i];
            if(!s.empty()){
                dp[i]=max(dp[i],nums[i]+ (*s.rbegin()).first);
            }            
            out=max(out,dp[i]);
            s.insert({dp[i],i});
        }
        for(int i=k;i<n;i++){
            if(i>k)s.erase({dp[i-k-1],i-k-1});
            dp[i]=max(dp[i],nums[i]+ (*s.rbegin()).first);
            s.insert({dp[i],i});
            out=max(out,dp[i]);

        }
        return out;
    }   
};