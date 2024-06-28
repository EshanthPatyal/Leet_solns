class Solution {
public:
        map<int,vector<int>> adj;
        vector<int> indegree;
    int dfs(int node,vector<int>&req,vector<int>&time){
        if(req[node]!=-1)return req[node];
        indegree[node]=-1;
        int ret=0;
        for(int i:adj[node]){
            ret=max(ret,dfs(i,req,time));
        }
        return req[node]=ret+time[node-1];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // v[0]=1;
        indegree.assign(n+1,0);
        for(auto it:relations){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        int out=0;
        // queue<int> q;
        vector<int> req(n+1,-1);
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                out=max(out,dfs(i,req,time));
            }
        }
        return out;
    }
};