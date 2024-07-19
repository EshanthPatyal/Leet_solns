class Solution {
public:
    bool check(string &s, int left, int right){
        while(left<right){
             if(s[left]!=s[right]) return false;
             left++;
             right--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        for(int i=n-1;i>=0;i--){
            int curr=INT_MAX;
            for(int j=i;j<n;j++){
                if(check(s,i,j)){
                    curr=min(curr,1+dp[j+1]);
                }
            }
            dp[i]=curr;
        }
        return dp[0];
    }
};