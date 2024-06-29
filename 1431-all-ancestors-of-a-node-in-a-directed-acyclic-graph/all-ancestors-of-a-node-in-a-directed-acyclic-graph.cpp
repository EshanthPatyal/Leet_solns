class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n,0);
        map<int,vector<int>> adj;
        for(auto it:edges){
            indeg[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<set<int>>ancestors(n);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it:adj[temp]){
                indeg[it]--;
                ancestors[it].insert(temp);
                for(int anc:ancestors[temp]){
                    ancestors[it].insert(anc);
                }
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        
        }
        vector<vector<int>> ret(n);
        for(int i=0;i<n;i++){
            for(auto it:ancestors[i]){
                ret[i].push_back(it);
            }
            sort(ret[i].begin(), ret[i].end());
        }
        return ret;

    }
};