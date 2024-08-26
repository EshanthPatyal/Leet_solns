class Solution {
public:
    vector<vector<int>> ret;
    map<int,int>mp;
    void recur(vector<int>&t,int n){
        if(t.size()==n){
            ret.push_back(t);
            return;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>0){
                t.push_back(it->first);
                it->second--;
                recur(t,n);
                t.pop_back();
                it->second++;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> t;
        for(auto it:nums){
            mp[it]++;
        }
        // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
        recur(t,n);
        return ret;
    }
};