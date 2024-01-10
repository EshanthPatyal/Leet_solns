class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& v) {
        map<int,int>mp;
        for(int i=0;i<v.size();i++){
            mp.insert({v[i][0],i});
        }
        vector<int> ret;
        for(auto it:v){
                auto it2=mp.lower_bound(it[1]);
                if(it2==mp.end())ret.push_back(-1);
                else{
                    ret.push_back(it2->second);
                }
            
        }
        return ret;

    }
};