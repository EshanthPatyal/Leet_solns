class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans1=i,ans2=i+1;
            }
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<n-i;j++){
                int r=j+i;
                if(s[r]==s[j] && dp[j+1][r-1]){
                    dp[j][r]=1;
                    ans1=j,ans2=r;
                }
            }
        }
        return s.substr(ans1,ans2-ans1+1);
    }
};