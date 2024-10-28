class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int m=0;for(auto it:nums)m=max(m,it);
        vector<int> v(m+1,0);
        for(auto it:nums)v[it]++;
        int out=1;
        for(auto it:nums){
            int curr=v[it];
            if(curr==0)continue;
            curr=1;
            long long j=it;
            j*=j;
            while(j<=m && v[j]!=0){
                curr++;
                if(j==m)break;
                j*=j;
            }
            out=max(out,curr);
        }
        return out==1?-1:out;
    }
};