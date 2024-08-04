class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int,map<int,int>>mp;
        for(auto it:pick){
            mp[it[0]][it[1]]++;
        }
        int o=0;
        for(int i=0;i<n;i++){
            map<int,int>col=mp[i];
            for(auto it:col){
                if(it.second>i){
                    o++;
                    break;
                }
            }
        }
        return o;
    }
};