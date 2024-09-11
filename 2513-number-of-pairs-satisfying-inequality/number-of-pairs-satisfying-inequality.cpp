class Solution {
public:
    long long out=0;
    void count(vector<int>&nums,int start,int mid,int end,int d){
        int l=start;
        int r=mid+1;
        while(l<=mid && r<=end){
            if((long)nums[l]<=(long)nums[r]+d){
                out+=(end-r+1);
                l++;
            }
            else{
                r++;
            }
        }
        sort(nums.begin()+start, nums.begin()+end+1);
        return;

    }

    void mergesort(vector<int>&v,int l,int r,int d){
        if(l==r)return;
        int m=(l+r)/2;
        mergesort(v,l,m,d);
        mergesort(v,m+1,r,d);

        count(v,l,m,r,d);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=nums1[i]-nums2[i];
        }
        mergesort(v,0,n-1,diff);
        return out;

    }
};