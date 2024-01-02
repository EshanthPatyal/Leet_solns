class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<vector<int>> ret;
        int c=1;
        while(c<=nums.size()){
            vector<int> v;
            for(auto& it:mp){
                if(it.second>0){
                    v.push_back(it.first);
                    c++;
                    it.second--;
                }
            }
            ret.push_back(v);
            v.clear();
        }
        return ret;
    }
};