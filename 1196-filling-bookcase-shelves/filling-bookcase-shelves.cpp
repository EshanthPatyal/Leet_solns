class Solution {
public:
    int recur(int i,int wleft,int curr_height,vector<vector<int>>&dp,vector<vector<int>>&b,int w){
        if(i==b.size()){
            return curr_height;
        }
        if(dp[i][wleft]!=-1)return dp[i][wleft];
        int next_layer=curr_height + recur(i+1,w-b[i][0],b[i][1],dp,b,w);
        int same=INT_MAX;
        if(b[i][0]<=wleft){
            same=recur(i+1,wleft-b[i][0],max(curr_height,b[i][1]),dp,b,w);
        }
        return  dp[i][wleft]=min(same,next_layer);

    }
    int minHeightShelves(vector<vector<int>>& books, int w) {
        int n=books.size();
        vector<vector<int>> dp(n,vector<int>(1010,-1));
        return recur(0,w,0,dp,books,w);
    }
};