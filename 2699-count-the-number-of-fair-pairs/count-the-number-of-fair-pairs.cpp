class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long out=0;
        for(int k=0;k<nums.size();k++){
            //iterator to search result - begin
            int x=lower_bound(nums.begin()+k+1, nums.end(), lower-nums[k])-nums.begin();
            int y=upper_bound(nums.begin()+k+1, nums.end(), upper-nums[k])-nums.begin();
            out+=(y-x);
        }
        return out;
    }
};