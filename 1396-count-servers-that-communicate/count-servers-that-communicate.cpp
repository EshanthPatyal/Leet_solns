class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int out=0;
        vector<int> rows(m,0);
        vector<int> columns(n,0);
        for(int i=0;i<m;i++){
            int curr=0;
            for(int j=0;j<n;j++)curr+=grid[i][j];
            // if(curr>1)out+=curr;
            rows[i]=curr;
        }
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<m;j++)curr+=grid[j][i];
            // if(curr>1)out+=curr;
            columns[i]=curr;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && (rows[i]>1 || columns[j]>1)){
                    // out+=(rows[i]-1);
                    // out+=(columns[j]-1);
                    out++;
                }
            }
        }
        return out;

    }
};