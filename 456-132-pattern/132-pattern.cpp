class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3)return false;
        int right=INT_MIN;
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<right){
                return true;
            }
            else{
                while(!s.empty() && nums[i]>s.top()){
                    right=s.top();
                    s.pop();
                }
                s.push(nums[i]);

            }
        }
        return false;
    }
};