class Solution {
public:
    bool f(string s,int idx,int n,vector<vector<char>>& v,int i,int j){
        if(idx==n){
            return true;
        }
        if(i>=v.size() || j>=v[0].size() || i<0 || j<0){
            return false;
        }
        if(v[i][j]!=s[idx]){
            return false;
        }

        if(v[i][j]==s[idx]){
            char c=v[i][j];
            v[i][j]='1';
            bool a=false;
            a= f(s,idx+1,n,v,i+1,j) || 
            f(s,idx+1,n,v,i,j+1) || 
            f(s,idx+1,n,v,i-1,j) ||
            f(s,idx+1,n,v,i,j-1);
            v[i][j]=c;
            return a;
        }
        return false;
    }
    bool exist(vector<vector<char>>& v, string s) {
        bool a=false;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(s[0]==v[i][j]){
                    a=a||f(s,0,s.length(),v,i,j);
                    if(a){
                        return a;
                    }
                }
            }
        }
        return a;
    }
};