class Solution {
public:
    int diff(char a,char b){
        int a1=a-'A';
        int x1=a1/6,y1=a1%6;
        
        int b1=b-'A';
        int x2=b1/6,y2=b1%6;
        return abs(x1-x2)+abs(y1-y2);

    }
    int minimumDistance(string word) {
        int n=word.size(),out=1e5;
        vector<vector<vector<int>>> dp(26,vector<vector<int>>(26,vector<int>(n+1,0)));
        for(int k=1;k<=n;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    int d1=diff(word[k-1],'A'+i),d2=diff(word[k-1],'A'+j);
                    dp[i][j][k]=min(dp[word[k-1]-'A'][j][k-1]+d1,dp[i][word[k-1]-'A'][k-1]+d2);
                    if(k==n)out=min(out,dp[i][j][k]);
                }
            }
        }
        return out;

    }
};