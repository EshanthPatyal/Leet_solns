class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> hist(m,0);
        int ret=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1')hist[j]+=mat[i][j]-'0';
                else hist[j]=0;
            }
            stack<int> st;
            for(int j=0;j<=m;j++){
                while(!st.empty()  &&  (j==m || hist[st.top()]>hist[j]) ){
                    int m=st.top();
                    st.pop();
                    int r=st.empty()?-1:st.top();
                    int l=j;
                    int dif=l-1-r;
                    ret=max(ret,hist[m]*dif);
                }
                st.push(j);
            }
        }
        return ret;
    }
};