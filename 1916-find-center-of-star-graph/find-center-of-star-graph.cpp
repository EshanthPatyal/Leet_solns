class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>v(edges.size()+1,0);
        int n=edges.size();
        for(auto it:edges){
            v[it[0]-1]++;
            v[it[1]-1]++;
            if(v[it[0]-1]==n){
                return it[0];
            }
            if(v[it[1]-1]==n){
                return it[1];
            }
        }
        return -1;
    }
};