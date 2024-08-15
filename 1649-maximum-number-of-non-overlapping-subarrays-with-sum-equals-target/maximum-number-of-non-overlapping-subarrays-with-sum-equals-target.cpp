class Solution {
public:
    int maxNonOverlapping(vector<int>& v, int target) {
        unordered_map<int,int>mp;
        int prev=-1;
        int c=0;
        int sum=0,i=0;
        mp[0]=-1;
        for(;i<v.size();i++){
            sum+=v[i];
            if(mp.find(sum-target)!=mp.end()){
                if(mp[sum-target]>=prev){
                    // cout<<mp[sum-target]<<" "<<i<<" "<<sum<<endl;
                    c++;
                    prev=i;
                }
            }
            mp[sum]=i;
        }
        return c;
    }
};