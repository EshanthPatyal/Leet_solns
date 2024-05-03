class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s;
        for(auto it:nums){
            if(it<0){
                s.insert(it);
            }
        }
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<nums.size();i++){
            if(s.find(-nums[i])!=s.end()){
                return nums[i];
            }
        }
        return -1;
    }
};