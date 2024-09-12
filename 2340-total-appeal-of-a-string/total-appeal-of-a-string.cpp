class Solution {
public:
    long long appealSum(string s) {
        int n=s.length();
        vector<long long>dp(n+1,0);
        vector<int> v(26,-1);
        for(int i=0;i<n;i++){
            char c=s[i];
            if(v[c-'a']!=-1){
                dp[i+1]+=dp[i]+(i+1-v[c-'a']);
                v[c-'a']=i+1;
            }
            else{
                dp[i+1]+=dp[i]+(i+1);
                v[c-'a']=i+1;
            }
        }
        long long out=0;
        for(auto it:dp)out+=it;
        return out;
    }
};