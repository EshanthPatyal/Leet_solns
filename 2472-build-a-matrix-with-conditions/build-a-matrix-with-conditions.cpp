class Solution {
public:
    vector<int> topo(int k, vector<int>& deg,map<int,vector<int>>& adj){
        queue<int> q;
        for (int i = 1; i<=k; i++) {
            if (deg[i] == 0) 
                q.push(i);
        }

        int count=0;
        vector<int> ans;
        while(!q.empty()){
            int j=q.front();
            q.pop();
            ans.push_back(j);
            count++;
            for(int k:adj[j]){
                deg[k]--;
                if (deg[k] == 0) {
                    q.push(k);
                }
            }
        }
        if(count != k) return {};
        return ans ;

    }        
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        vector<int> ind1(k+1,0),ind2(k+2,0);
        vector<vector<int>> ret(k, vector<int>(k));
        map<int,vector<int>> adj1;
        for(auto it:r){
            ind1[it[1]]++;
            adj1[it[0]].push_back(it[1]);
        }
        map<int,vector<int>> adj2;
        for(auto it:c){
            ind2[it[1]]++;
            adj2[it[0]].push_back(it[1]);
        }
        auto row=topo(k, ind1, adj1);
        auto col=topo(k, ind2, adj2);
        if (row.empty()|| col.empty())
            return {};

        vector<int> ind_i(k+1, -1), ind_j(k+1, -1);
        for(int i=0; i<k; i++){
            ind_i[row[i]]=i;
            ind_j[col[i]]=i;
        }

        for(int x=1; x<=k; x++)
            ret[ind_i[x]][ind_j[x]]=x;
        
        return ret;        

    }
};