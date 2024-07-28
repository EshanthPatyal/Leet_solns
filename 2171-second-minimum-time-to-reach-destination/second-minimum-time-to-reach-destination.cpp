class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        map<int,vector<int>>adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }   
        vector<int> v(n+1,0),d1(n+1,INT_MAX),d2(n+1,INT_MAX);     
        queue<pair<int,int>> q;
        q.push({1,0});
        d1[1]=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int no=temp.first,dis=temp.second;
            for(auto it:adj[no]){
                if(dis+1<d1[it]){
                    d2[it]=d1[it];
                    d1[it]=dis+1;
                    q.push({it,dis+1});
                }
                else if(dis+1>d1[it] && dis+1<d2[it]){
                    d2[it]=dis+1;
                    q.push({it,dis+1});
                }
            }
        }
        int ret=0;
        for(int i=0;i<d2[n];i++){
            int cur=ret/change;
            if(cur%2){
                ret+=change-(ret%change);
            }
            ret+=time;
        }
        return ret;
    }
};