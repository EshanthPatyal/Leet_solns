class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> v(nums.size(),0);
        for(int i=1;i<nums.size();i++){
            if((nums[i]+nums[i-1])%2!=0){
                v[i]=v[i-1]+1;
            }
            else{
                v[i]=v[i-1];
            }
        }
        vector<bool> ret(q.size(),false);
        for(int i=0;i<ret.size();i++){
            int l=q[i][0],r=q[i][1];
            if(v[r]-v[l]==r-l){
                ret[i]=true;
            }
        }
        return ret;

    }
};