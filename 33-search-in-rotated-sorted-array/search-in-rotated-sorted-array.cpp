class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            // cout<<nums[low]<<" ";
            // cout<<nums[mid]<<" ";
            // cout<<nums[high]<<endl;
            if(low==high){
                index=low;
                break;
            }
            if(nums[mid]<nums[high]){
                high=mid;
            }
            else if(nums[mid]>nums[low]){
                low=mid;
            }
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else if(nums[mid]<nums[low]){
                high=mid-1;
            }

        }
        int ans;
        high=nums.size()-1;        
        if(nums[high]>=target){
                low=index;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(nums[mid]==target){
                        ans=mid;
                        break;
                    }
                    else if(nums[mid]<target){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
        }
        
        else if(nums[high]<target){
                low=0;
                high=index-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(nums[mid]==target){
                        ans=mid;
                        break;
                    }
                    else if(nums[mid]<target){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
        }
        return nums[ans]==target? ans:-1;
    }
};