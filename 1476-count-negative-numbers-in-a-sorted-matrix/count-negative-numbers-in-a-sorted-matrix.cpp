class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size()-1;
        int c=0;
        int out=0;
        while(r>=0 && c<grid[0].size()){
            while(c<grid[0].size() && grid[r][c]>=0){
                c++;
            }
            out+=(grid[0].size()-c);
            r--;
        }
        return out;
    }
};