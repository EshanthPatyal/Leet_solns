class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp1;
        map<int,int>mp2;
        set<int> v;
        vector<vector<int>> ret;
        vector<int> temp1,temp2;
        for(auto it:matches){
            v.insert(it[0]);
            v.insert(it[1]);
            mp1[it[0]]++;
            mp2[it[1]]++;
        }
        for(auto it: v){
            if(mp2.find(it)==mp2.end() && mp1.find(it)->second>=1){
                temp1.push_back(it);
            }
            else if(mp2[it]==1){
                temp2.push_back(it);
            }
        }
        ret.push_back(temp1);
        ret.push_back(temp2);
        return ret;
    }
};