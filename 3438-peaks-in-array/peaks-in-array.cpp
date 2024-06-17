class Solution {
public:
struct segtree{
    int size;
    vector<int> sums;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        sums.assign(2*size,0);
    }
    void set(int i,int v,int x,int l,int r){
        if(r-l==1){
            sums[x]=v;
            return;
        }
        int m=(l+r)/2;
        if(i<m){
            set(i,v,2*x+1,l,m);
            // return;
        }
        else{
            set(i,v,2*x+2,m,r);
            // return;
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }

    int sum(int lx,int rx,int x,int l,int r){
        if(l==r || rx<=l || r<=lx)return 0;
        if(lx<=l && rx>=r)return sums[x];
        int m=(l+r)/2;
        return sum(lx,rx,2*x+1,l,m)+sum(lx,rx,2*x+2,m,r);
    }
    int sum(int lx,int rx){
        return sum(lx,rx,0,0,size);
    }

};
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& q) {
        segtree st;
        int n=nums.size();
        st.init(nums.size());
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                st.set(i,1);
            }
        }
        vector<int> ret;
        for(int i=0;i<q.size();i++){
            if(q[i][0]==1){
                ret.push_back(st.sum(q[i][1]+1,q[i][2]));
            }
            else{
                int idx=q[i][1];
                nums[idx]=q[i][2];
                if(idx>0 && idx<n-1 ){
                    if(nums[idx]>nums[idx-1] && nums[idx]>nums[idx+1]){
                        st.set(idx,1);
                    }
                    else{
                         st.set(idx,0);  
                    }
                }
                if(idx>1){
                    if(nums[idx-1]>nums[idx-2] && nums[idx-1]>nums[idx]){
                        st.set(idx-1,1);
                    }
                    else {
                        st.set(idx-1,0);
                    }
                }
                if(idx<n-2){
                    if(nums[idx+1]>nums[idx] && nums[idx+1]>nums[idx+2]){
                        st.set(idx+1,1);
                    }
                    else {
                        st.set(idx+1,0);
                    }
                }
            }
        }
        return ret;
    }
};