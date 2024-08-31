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
        // vector<vector<int>> pal(n,vector<int>(n,0));
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         pal[i][j]=check(i,j);
        //         pal[j][i]=check(j,i);
        //     }
        // }
        for(int i=0;i<n;i++){
            dp[i]=max(dp[i],i==0?0:dp[i-1]);
            int curr=0;
            for(int j=i-k+1;curr<2 && j>=0; curr++ , j--){
                dp[i]=max(dp[i],(j==0?0:dp[j-1])+check(j,i));
            }
        }
        return dp[n-1];
    }
};