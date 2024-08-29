class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> vis(n,false);
        queue<int> q;
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int a=q.front();
                    q.pop();
                    auto curr=stones[a];
                    for(int j=0;j<n;j++){
                        if(j==a) continue;
                        if(curr[0]==stones[j][0] ||  curr[1]==stones[j][1] ){
                            //cout<<j<<endl;
                            if(vis[j]==false){
                                q.push(j);
                                vis[j]=true;
                                ans++;
                            }
                        }
                    }

                }
            }    
        }
        return ans;
    }
};