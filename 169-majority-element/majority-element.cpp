class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int curr_element;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                curr_element=nums[i];
                count++;
            }
            else if(nums[i]==curr_element){
                count++;
            }
            else{
                count--;
            }
        }
        return curr_element;
    }
};