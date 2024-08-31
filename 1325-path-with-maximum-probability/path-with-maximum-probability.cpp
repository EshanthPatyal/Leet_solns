class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], pro[i]});
            adj[edges[i][1]].push_back({edges[i][0], pro[i]});   
        }
        vector<int> vis(n, 0);
        
        priority_queue<pair<double, int>> pq;
        pq.push({(double)1.0, start});
        
        vector<double> dist(n, (double)0.0);
        dist[start] = 1.0;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            double proba = it.first;
            int node = it.second;
            if(!vis[node]) {
                vis[node]=1;
                for(auto v: adj[node]) {
                    if (dist[v.first] < v.second*proba) {
                        dist[v.first] = v.second*proba;
						pq.push({dist[v.first], v.first});
                    }
                }
            }
        }
        return dist[end];
    }
};