class Solution {
public:
    bool cycle(unordered_map<int, vector<int>>& adj,int node, vector<int>& vis){
        if(vis[node]==2){
            return false;
        }
        vis[node]=2;
        bool a=true;
        for(auto it:adj[node]){
            if(vis[it]!=1)
                a=cycle(adj,it,vis);
                if(a==false){
                    return a;
                }
        }
        vis[node]=1;
        return true;
    }
    int largestPathValue(string s, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = s.length();
        vector<int> vis(n, 0), indegree(n, 0);
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        // for (int i = 0; i < n; i++) {
        //     if (vis[i] == 0) {
        //         bool a=cycle(adj,i,vis);
        //         if(a==false)return -1;
        //     }
        // }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i][s[i]-'a']++;
            }
        }
        int ret=0;
        int count=0;
        while(!q.empty()){
            count++;
            int node=q.front();
            q.pop();
            int curmax=0;
            for(auto it:dp[node]){
                curmax=max(curmax,it);
            }
            ret=max(ret,curmax);
            for(auto it:adj[node]){
                for(int i=0;i<26;i++){
                    dp[it][i]=max(dp[it][i],dp[node][i] +(i==(s[it]-'a')) );
                }
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(count<n)return -1;
        return ret;

        // return 0;
    }
};