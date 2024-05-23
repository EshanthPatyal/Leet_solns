class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<int> row(grid.size(),0),col(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            int s=0;
            for(int j=0;j<grid[0].size();j++){
                s+=grid[i][j];
            }
            row[i]=s;
        }
        for(int i=0;i<grid[0].size();i++){
            int s=0;
            for(int j=0;j<grid.size();j++){
                s+=grid[j][i];
            }
            col[i]=s;
        }
        long long sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    sum+=(row[i]-1)*(col[j]-1);
                }
            }
        }
        return sum;


    }
};