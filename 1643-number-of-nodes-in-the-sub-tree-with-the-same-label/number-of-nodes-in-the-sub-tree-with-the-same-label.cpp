class Solution {
public:
    vector<int> recur(int i,vector<vector<int>>& adj, vector<int>& ret,string& s){
        vector<int>v(26,0);
        ret[i]=1;
        v[s[i]-'a']=1;
        for(int j=0;j<adj[i].size();j++){
            if(!ret[adj[i][j]]){
                vector<int> tmp=recur(adj[i][j],adj,ret,s);
                for(int k=0;k<26;k++)v[k]+=tmp[k];
            }
        }
        ret[i]=v[s[i]-'a'];
        return v;
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ret(n,0);
        recur(0,adj,ret,labels);
        return ret;
    }
};