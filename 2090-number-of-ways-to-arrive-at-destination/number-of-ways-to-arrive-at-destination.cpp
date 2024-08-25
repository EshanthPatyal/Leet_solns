#define ll long long
class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        map<int,vector<pair<int,int>>>adj;
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<ll> dist(n, LONG_MAX);
        vector<ll> dp(n);        
        dp[0]=1;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [w,u] = pq.top();
            pq.pop();
            if(w>dist[u])continue;
            for(auto [v,d]:adj[u]){
                if(dist[v]>=w+d){
                    if(dist[v]==w+d) {
                        dp[v]+=dp[u];
                        dp[v]%=mod;
                        continue;
                    }                    
                    dist[v]=w+d;
                    dp[v]=dp[u];
                    pq.push({dist[v],v});
                    dp[v]%=mod;
                }
            }
        }
        return dp[n-1];
    }
};