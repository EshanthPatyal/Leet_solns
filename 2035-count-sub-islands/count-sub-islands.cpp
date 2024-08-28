class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        if(i<0 || j<0 || i>=grid1.size() || j>=grid1[0].size())return true;
        // cout<<i<<j<<endl;
        if(grid2[i][j]==0){
            return true;
        }
        bool a=false;
        if(grid2[i][j]==1 && grid1[i][j]==1){
            a=true;
        }
        grid2[i][j]=0;
        bool e= check(i+1,j,grid1,grid2);
        bool b= check(i-1,j,grid1,grid2);
        bool c= check(i,j-1,grid1,grid2);
        bool d= check(i,j+1,grid1,grid2);      
        return a&&b&&c&&d&&e;       
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int m=grid1.size(),n=grid1[0].size();
        int out=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==1 && grid2[i][j]==1){
                    bool a=check(i,j,grid1,grid2);
                    // cout<<i<<" "<<j<<" "<<a<<endl;
                    if(a){
                        out++;
                    }
                }
            }
        }
        return out;
    }
};