class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj,map<int,int>&ind,map<char,int>&al,vector<int>&vis,int i,string& s){
        ind.insert({i,1});
        // al.insert({s[i]});
        al[s[i]]++;
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it]==1)continue;
            dfs(adj,ind,al,vis,it,s);
        }
        return ;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> adj;
        for(auto it:pairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==1)continue;
            map<int,int>indices;
            map<char,int>alphas;
            dfs(adj,indices,alphas,vis,i,s);
            vector<int> temp;
            for(auto it:indices){
                while(it.second--)temp.push_back(it.first);
            }
                // for(auto it:alphas)cout<<it<<" "<<i<<" ";
            int c=0;
            for(auto it:alphas){
                while(it.second--){
                    s[temp[c]]=it.first;
                    c++;
                }
            }
        }
        return s;
    }
};