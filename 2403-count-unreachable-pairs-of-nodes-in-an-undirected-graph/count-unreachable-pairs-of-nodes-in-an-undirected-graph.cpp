class Solution {
public:
    vector<int> components;
    void dfs(map<int,vector<int>>&adj , int node , vector<int>&vis , long long& curr){
        if(vis[node]==1)return ;
        vis[node]=1;
        // curr.push_back(node);
        curr++;
        for(auto id:adj[node]){
            dfs(adj,id,vis,curr);
        }
    }
    long long countPairs(int n, vector<vector<int>>& e) {
        map<int,vector<int>> adj;
        for(auto edges:e){
            adj[edges[0]].push_back(edges[1]);
            adj[edges[1]].push_back(edges[0]);
        }
        vector<int> vis(n,0);
        long long out=0;
        long long visited=n;
        for(int i=0;i<n;i++){
            // vector<int> curr;
            long long curr=0;
            dfs(adj,i,vis,curr);
            out+=(curr)*(visited-curr);
            visited-=curr;
            // components.push_back(curr);
        }

        return out;


    }
};