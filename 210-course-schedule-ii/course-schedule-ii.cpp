class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         map<int,vector<int>> adj;
        vector<int> indeg(n,0);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        vector<int> ret;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i=q.front();
            q.pop();
            ret.push_back(i);
            for(auto it:adj[i]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(ret.size()==n){
            return ret;
        }        
        return {};
    }
};