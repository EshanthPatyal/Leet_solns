class Solution {
public:
    int a,b;
    void bfs(int node,map<int,vector<int>>&adj,vector<int>&v){
        // if(v[node]==1)return;
        a++;
        for(auto it:adj[node]){
            b++;
            if(v[it]==0){
                v[it]=1;
                bfs(it,adj,v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>v(n,0);
        int out=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                v[i]=1;
                a=0,b=0;
                bfs(i,adj,v);
                if(b==(a)*(a-1)){
                    out++;
                }
                // cout<<i<<" "<<a<<" "<<b<<endl;
            }
        }
        return out;

    }


};