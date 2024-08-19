class Solution {
public:
    vector<long long> djik(int n , int s ,vector<vector<pair<int,int>>> &adj){
        vector<long long> dist(n,1e14);
        dist[s] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            for(auto v : adj[u.second]){
                if(u.first + v.second < dist[v.first]){
                    dist[v.first] = u.first + v.second;
                    pq.push({dist[v.first],v.first});
                }
            }
        }
        return dist;
    }        
    
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<bool> ret(edges.size(),false);
        vector<long long> fwd = djik(n,0,adj);
        vector<long long> bwd= djik(n,n-1,adj);
        long long mini = fwd[n-1];
        if(mini==1e14) return ret;
        for(int i=0;i<edges.size();i++){
            auto it=edges[i];
            if(fwd[it[0]]+bwd[it[1]]+it[2]==mini || bwd[it[0]]+fwd[it[1]]+it[2]==mini){
                ret[i]=true;
            }
        }
        return ret;                
    }
};