class Solution {
public:
    int c=0;
    int check(int node,vector<int>&edge,vector<int>&vis,vector<bool>&ve){
        // int cur=0;
        if(ve[node])return -1;
        if(edge[node]==-1){
            ve[node]=1;
            return -1;
        }
        if(vis[node]!=0){
            return c-vis[node]+1;
        }
        vis[node]=c+1;
        c++;
        int ret=check(edge[node],edge,vis,ve);
        vis[node]=0;
        ve[node]=1;
        return ret;
    }
    int longestCycle(vector<int>& edges) {
            // [-1,4,-1,2,0,4]
        int n=edges.size();
        vector<int> vis(n,0);
        int ans=-1;
        vector<bool> ve(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                // cout<<"new"<<endl;
                c=0;
                int temp=check(i,edges,vis,ve);
                if(temp!=0)ans=max(ans,temp);
                // ve.clear();
            }

        }
        return ans;
    }
};