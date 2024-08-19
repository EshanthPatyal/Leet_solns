class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n+1,0);
        vector<vector<int>> vec(n+1,vector<int>(n+1,0));
        unordered_map<int,vector<int>> adj;        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            vec[it[0]][it[1]]=1;
            vec[it[1]][it[0]]=1;
            degree[it[0]]++;
            degree[it[1]]++;
        }
        int ret=INT_MAX;
        for(int u=1;u<=n;u++){
            for(auto v:adj[u]){
                for(auto w:adj[v]){
                    if(vec[u][v]==1 && vec[v][w]==1 && vec[w][u]==1){
                        ret=min(ret,degree[u]+degree[v]+degree[w]-6);
                    }
                }
            }
        }
        return ret==INT_MAX?-1:ret;
    }
};