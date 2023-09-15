class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& v) {
        map<int,list<pair<int,int>>>adj;
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1]);
                adj[i].push_back({j,a});
                adj[j].push_back({i,a});
            }
        }
        priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;
        // weight,node no to reach
		vector<int> vis(n, 0);
        pq.push({0,0});
        int s=0;
        while(!pq.empty()){
            auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            s+=wt;
            for (auto it : adj[node]) {
				int nextNode = it.first;
				int nextWt = it.second;
				if (!vis[nextNode]) {
					pq.push({nextWt, nextNode});
				}
			}
        }
        return s;
    }
};