class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n,vector<int>  (n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            dp[edges[i][0]][edges[i][1]]=edges[i][2];
            dp[edges[i][1]][edges[i][0]]=edges[i][2];
        }
		for (int i=0;i<n;i++)
                dp[i][i] = 0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]==INT_MAX || dp[k][j]==INT_MAX){
                        continue;
                    }
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int curr_min=INT_MAX;
        int a=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(dp[i][j]<=distanceThreshold ){
                    temp++;
                }
                //cout<<dp[i][j]<<" ";
            }
            if(temp<=curr_min ){
                curr_min=temp;
                a=i;
            }
            
            //cout<<endl;
        }
        return a;
    }
};