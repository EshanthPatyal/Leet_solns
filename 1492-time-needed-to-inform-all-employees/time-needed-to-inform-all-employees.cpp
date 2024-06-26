class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            if(i!=headID){
                adj[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        int out=0;
        q.push({headID,0});
        while(!q.empty()){
            int a=q.size();
            // int cur_max=0;
            while(a--){
                int cur=q.front().first;
                out=max(out,q.front().second);
                for(auto it:adj[cur]){
                    q.push({it,q.front().second+informTime[cur]});
                }
                q.pop();
            }
            // out+=cur;
        }
        return out;
    }
};