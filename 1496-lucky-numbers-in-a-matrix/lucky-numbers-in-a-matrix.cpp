class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> row(m,INT_MAX),col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i]=min(row[i],mat[i][j]);
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                col[j]=max(col[j],mat[i][j]);
            }
        }
        vector<int>ret;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(mat[i][j]==col[j] && mat[i][j]==row[i]){
                    ret.push_back(mat[i][j]);
                }
            }
        }
        return ret;

    }
};