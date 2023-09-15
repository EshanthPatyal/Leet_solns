class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        map<int,vector<int>>mp;
        int n=v.size();
        for(int i=0;i<n;i++){
            mp[v[i]].push_back(i);
        }
        vector<vector<int>> ret;
        for(auto it: mp){
            int a=it.first;
            vector<int> temp;
            for(auto num:it.second){
                temp.push_back(num);
                if(temp.size()==a){
                    ret.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ret;
    }
};