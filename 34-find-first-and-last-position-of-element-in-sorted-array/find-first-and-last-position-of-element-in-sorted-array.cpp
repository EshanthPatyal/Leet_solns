class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            int start = 0;
            int end =nums.size()-1;
            int res = -1;

            while (start <= end) {
                int mid = (end + start) / 2;
                if (nums[mid] == target) {
                    res = mid;
                    end = mid - 1;

                } 
                else if (target < nums[mid]) {
                    end = mid - 1;
                }  
                else {
                    start = mid + 1;
                }
            }
            if(res==-1){
                return {-1,-1};
            }
            start=0;
            end=nums.size()-1;
            int res1=-1;
            while (start <= end) {
                int mid = (end + start) / 2;
                if (nums[mid] == target) {
                    res1 = mid;
                    start = mid + 1;

                } 
                else if (target < nums[mid]) {
                    end = mid -1;
                } 
                else {
                    start = mid + 1;
                }
            }
            return{res,res1};
    }
};