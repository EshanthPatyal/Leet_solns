class NumMatrix {
public:
    vector<vector<long long>> temp;
    NumMatrix(vector<vector<int>>& matrix) {
        temp.resize(matrix.size()+1,vector<long long>(matrix[0].size()+1,0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                    temp[i+1][j+1]=temp[i+1][j]+temp[i][j+1]+matrix[i][j]-temp[i][j];
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return  temp[row2+1][col2+1]-temp[row2+1][col1]-temp[row1][col2+1]+temp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */