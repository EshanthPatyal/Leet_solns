class Solution {
public:
    int dp[100005][3];
    int helper(vector<int>& nums1, vector<int>& nums2,int i,int arr_no){
        if(i>=nums1.size()){
            return 0;
        }
        if(dp[i][arr_no]!=-1){
            return dp[i][arr_no];
        }
        int ans=0;
        if(arr_no==0){ 
            int non=helper(nums1,nums2,i+1,0);
            int fir=1+helper(nums1,nums2,i+1,1);
            int sec=1+helper(nums1,nums2,i+1,2);
            ans=max(ans,fir);
            ans=max(sec,ans);
            ans=max(non,ans);
        }
        else{
            if(arr_no==1){
                if(nums1[i]>=nums1[i-1]){
                    ans=max(1+helper(nums1,nums2,i+1,1),ans);
                }
                if(nums2[i]>=nums1[i-1]){
                    ans=max(1+helper(nums1,nums2,i+1,2),ans);
                }
            }
            if(arr_no==2){
                if(nums2[i]>=nums2[i-1]){
                    ans=max(1+helper(nums1,nums2,i+1,2),ans);
                }
                if(nums1[i]>=nums2[i-1]){
                    ans=max(1+helper(nums1,nums2,i+1,1),ans);
                }
            }
        }
        return dp[i][arr_no]=ans;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return helper(nums1,nums2,0,0);
    }
};