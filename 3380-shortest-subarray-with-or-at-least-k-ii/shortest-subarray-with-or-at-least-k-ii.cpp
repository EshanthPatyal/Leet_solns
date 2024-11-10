class Solution {
public:
    vector<int> b;
    int calc(){
        int c=0;
        for(int i=0;i<32;i++){
            if( b[i] > 0){
                c+=1<<i;
            }
        }
        return c;
    }
    void rem(int a,int f){
        int o=0;
        for(int i=0;i<32;i++){
            if((a & (1<<i) )){
                b[i]+=f;
            }
        }
        return;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int curr=0,i=0,j=0,out=INT_MAX;
        int n=nums.size();
        b.assign(32,0);
        int cu=0;
        for(auto it:nums)cu=cu | it;
        if(cu>=k)out=n;
        while(j<n){
            rem(nums[j++],1);
            curr=calc();
            while(i<j && curr>=k){
                rem(nums[i++],-1);
                curr=calc();
                out=min(out,j-i+1);
            }
        }
        return out==INT_MAX?-1:out;
    }
};