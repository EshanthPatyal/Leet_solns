class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        map<int,int> mp;
        long long curr=0,ret=0;
        while(j<k){
            mp[nums[j++]]++;
        }
        if(k==1){
            for(auto it:nums)curr=max(curr,1LL*it);
            return curr;   
        }
        for(auto it:mp){
            curr+=(1LL*it.first);
        }
        if(mp.size()==k)ret=max(ret,curr);
        for(;j<n;j++){
            if(mp.find(nums[j])==mp.end()){
                mp[nums[j]]++;
                curr+=nums[j];
            }
            else mp[nums[j]]++;
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
                curr-=nums[i];
            }
            i++;
            if(mp.size()==k)ret=max(ret,curr);
        }
        return ret;
    }
};