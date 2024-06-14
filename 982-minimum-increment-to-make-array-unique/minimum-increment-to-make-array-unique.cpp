class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int>mp;
        long long o=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            int t=it.second;
            if(t>1){
                t--;
                o+=t;
                if(mp.find(it.first+1)==mp.end())mp[it.first+1]=t;
                else mp[it.first+1]+=t;
            }
        }
        return o;
    }
};