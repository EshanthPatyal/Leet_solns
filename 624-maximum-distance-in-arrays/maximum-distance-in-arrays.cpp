class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int c1=arrays[0][0], c2=arrays[0].back();
        int diff=0;
        for(int i=1; i<arrays.size(); i++){
            int a0=arrays[i][0], aN=arrays[i].back();
            diff=max({diff, aN-c1, c2-a0});
            c1=min(a0, c1);
            c2=max(aN, c2);
        }
       
        return diff;        
    }
};