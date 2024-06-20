class Solution {
public:
    int check(vector<int>&v,int k,int m){
        int prev=0,ans=-1,c=1;
        for(int i=1;i<v.size();i++){
            if(abs(v[i]-v[prev])>=k){
                c++;
                // ans=max(abs(v[i]-v[prev]),ans);
                prev=i;
            }
        }
            if(c>=m){
                return 1;
            }
            return -1;
    }
    int maxDistance(vector<int>& v, int m) {
        sort(v.begin(),v.end());
        int lo=1,hi=1e9;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int temp=check(v,mid,m);
            if(temp!=-1){
                ans=max(mid,ans);
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};