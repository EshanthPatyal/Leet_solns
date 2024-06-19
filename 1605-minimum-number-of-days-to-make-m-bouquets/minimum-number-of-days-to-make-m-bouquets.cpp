class Solution {
public:
    bool check(int d,vector<int>&v,int k,int m){
        int c=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=d){
                c++;
            }
            else if(v[i]>d){
                c=0;
            }
            if(c==k){
                c=0;
                m--;
            }
        }
        if(m<=0)return true;
        return false;
    }
    int minDays(vector<int>& v, int m, int k) {
        int lo=1,hi=1e9+1;
        int ans=-1;
        // cout<<check(9,v,k,m)<<endl;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            bool a=check(mid,v,k,m);
            if(a==true){
                ans=mid;
                // cout<<mid<<endl;
                hi=mid-1;
            }
            else{
                // cout<<"a"<<mid<<endl;
                lo=mid+1;
            }
        }
        return ans;
    }
};