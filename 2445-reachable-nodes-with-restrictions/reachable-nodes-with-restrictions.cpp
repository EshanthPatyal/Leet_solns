class Solution {
public:
int out=0;
    void dfs(map<int,vector<int>>&adj,int node,vector<int>& vis){
        if(vis[node])return;
        vis[node]=1;
        out++;
        for(auto it:adj[node]){
            dfs(adj,it,vis);
        }
        return ;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        set<int> s;
        for(auto it:r){
            s.insert(it);
        }
        map<int,vector<int>> adj;
        for(auto it:edges){
            if(s.count(it[0])==0 && s.count(it[1])==0){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        }

        vector<int> v(n,0);
        dfs(adj,0,v);
        return out;
    }
};