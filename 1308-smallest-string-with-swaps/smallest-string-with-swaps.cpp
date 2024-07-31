class Solution {
public:
    void dfs(map<int,vector<int>>& adj,multiset<int>&ind,multiset<char>&al,vector<int>&vis,int i,string& s){
        ind.insert(i);
        al.insert(s[i]);
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
        map<int,vector<int>> adj;
        for(auto it:pairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==1)continue;
            multiset<int>indices;
            multiset<char>alphas;
            dfs(adj,indices,alphas,vis,i,s);
            vector<int> temp;
            for(auto it:indices){
                temp.push_back(it);
            }
                // for(auto it:alphas)cout<<it<<" "<<i<<" ";
            int c=0;
            for(auto it:alphas){
                s[temp[c]]=it;
                c++;
            }
        }
        return s;
    }
};