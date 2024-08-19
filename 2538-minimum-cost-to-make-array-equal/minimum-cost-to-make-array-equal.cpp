class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<long long,long long>> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        vector<long long> cumm_cost(n,0),dp(n,0);
        sort(v.begin(),v.end());
        cumm_cost[0]=v[0].second;
        for(int i=1;i<n;i++){
            cumm_cost[i]=cumm_cost[i-1]+v[i].second;
        }
        for (int i=1;i<n; i++) {
            dp[0] += v[i].second*(v[i].first-v[0].first);
        }
        //cost of converting to i = dp[i]
        // i-1 to i transtion == diff=(v[i][0]-v[i-1][0])
        // +diff*cumm_cost[i-1]
        // -diff*cumm_cost[i...n-1] (i , i+1 ... n-1 all changed to i-1) == diff*(cumm_cost[n-1]-cumm_cost[i-1])
        long long ret=dp[0];
        for(int i=1;i<n;i++){
            long long diff=v[i].first-v[i-1].first;
            dp[i] = dp[i-1] + diff*cumm_cost[i-1] - diff*(cumm_cost[n-1]-cumm_cost[i-1]);
            ret=min(ret,dp[i]);
        }
        return ret;
    }
};