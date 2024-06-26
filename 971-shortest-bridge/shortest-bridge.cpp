class Solution {
public:
        queue<pair<int,int>>q;
    int n;
    vector<pair<int,int>> check;
    void dfs(int i,int j,vector<vector<int>>&g){
        if(i<0 || j<0 || i>=n || j>=n || g[i][j] == 2 || g[i][j] == 0){
            return ;
        }
        bool flag=true;
        g[i][j]=2;
        if(i-1>=0){
            if(g[i-1][j]){
                dfs(i-1,j,g);
            }
            else{
                flag=false;
            }
        }
        if(j-1>=0){
            if(g[i][j-1]){
                dfs(i,j-1,g);
            }
            else{
                flag=false;
            }
        }
        if(i+1<n){
            if(g[i+1][j]){
                dfs(i+1,j,g);
            }
            else{
                flag=false;
            }
        }
        if(j+1<n){
            if(g[i][j+1]){
                dfs(i,j+1,g);
            }
            else{
                flag=false;
            }
        }
        if(!flag){
            check.push_back({i,j});
        }
        return;
        
    }
    int bfs(vector<vector<int>>&g){
        int curr=0;
        int mini=INT_MAX;
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!q.empty()){
            int a=q.size();
            while(a--){
                auto t=q.front();
                q.pop();
                for(auto it:dir){
                    int dx=t.first+it[0];
                    int dy=t.second+it[1];
                    if(dx>=0 && dx<n && dy>=0 && dy<n){
                        if(g[dx][dy]==1){
                            mini=min(mini,curr);
                        }
                        else if(g[dx][dy]==0){
                            q.push({dx,dy});
                            g[dx][dy]=2;
                        }
                    }
                }
            }
            curr++;
        }
        return mini;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    i=n+1;
                    break;
                }
            }
        }
        int maxi=n;
        for(auto it:check){
            q.push(it);
        }

        return bfs(grid);
    }
};