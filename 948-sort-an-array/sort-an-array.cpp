class Solution {
public:
    void merge(int l,int m,int r,vector<int>&a,vector<int>&t){
        int i=l,j=m+1;
        int idx=l;
        while(i<=m && j<=r){
            if(a[i]<=a[j]){
                t[idx]=a[i];
                i++;
            }
            else if(a[i]>a[j]){
                t[idx]=a[j];
                j++;
            }
            idx++;
        }
        while(i<=m){
            t[idx]=a[i];
            idx++;i++;
        }
        while(j<=r){
            t[idx]=a[j];
            idx++;j++;        }
        for(int k=l;k<=r;k++)a[k]=t[k];
    }
    void mergesort(vector<int>&v,int beg,int end,vector<int>&temp){
        if (beg >= end)
            return;
        int mid = beg + (end - beg) / 2;
        mergesort(v, beg, mid, temp);
        mergesort(v, mid+1, end, temp);
        merge(beg, mid , end, v, temp);        
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergesort(nums,0,nums.size()-1,temp);
        return nums;
    }
};