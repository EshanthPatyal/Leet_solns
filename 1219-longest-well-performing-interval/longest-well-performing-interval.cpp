class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            if(i)v[i]+=v[i-1];

            if(hours[i]>8){
                v[i]++;
            }
            else{v[i]--;}
        }
        map<int,int> mp;
        mp[v[0]]=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i]>0){
                ans=max(ans,i+1);
            }
            else {
                if(mp.find(v[i])==mp.end()){
                    mp[v[i]]=i;
                }
                if(mp.find(v[i]-1)!=mp.end()){
                    ans=max(ans,i-mp[v[i]-1]);
                }   
            }
        }
        return ans;
    }
};