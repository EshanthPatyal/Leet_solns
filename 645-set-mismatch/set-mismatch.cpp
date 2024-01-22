class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[i+1]=1;
        }
        for(auto it:nums){
            mp[it]++;
        }
        int a=0,b=0;
        for(auto it:mp){
            if(it.second==3){
                a=it.first;

            }
            if(it.second==1){
                b=it.first;
            }
        }
        return {a,b};
    }
};