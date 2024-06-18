class Solution {
public:
    int s;
    long long out=0;
    int recur(unordered_map<int,vector<int>>& adj,vector<bool>&vis, int& node){
        if(vis[node])return 0;
        int a=1;
        vis[node]=true;
        for(auto it:adj[node]){
            a+=recur(adj,vis,it);
        }
        if(node)out+=(a/s+(a%s!=0));
        return a;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int,vector<int>>adj;
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        s=seats;
        vector<bool> vis(roads.size()+1,0);
        int t=0;
        recur(adj,vis,t);
        return out;

    }
};