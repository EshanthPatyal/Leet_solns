class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int i=0,j=0;
        map<int,int> mp;
        int ret=1;
        int curr_max=0;
        if(nums.size()==1){
            return 1;
        }
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;

            //cout<<mp[nums[j]]<<" "<<j<<endl;
            curr_max=max(curr_max,mp[nums[j]]);
            if(j-i+1-curr_max>k){
                mp[nums[i]]--;
                i++;
            }            
        }
        return curr_max;
    }
};