class Solution {
public:
    string curr;
    int n;
    int check(int i,int j){
        while(i<j){
            if(curr[i]!=curr[j])return 0;
            i++;j--;
        }
        return 1;
    }
    int maxPalindromes(string s, int k) {
        curr=s;
        n=s.length();
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++){
            dp[i]=max(dp[i],i==0?0:dp[i-1]);
            for(int j=i-k+1;j>=0;j--){
                dp[i]=max(dp[i],(j==0?0:dp[j-1])+check(j,i));
            }
        }
        return dp[n-1];
    }
};