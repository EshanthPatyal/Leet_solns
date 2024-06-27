class Solution {
public:
vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    int count(int i,int j,vector<vector<char>>&b){
        int ret=0;
        for(auto [dx,dy] : dirs){
            int x=i+dx,y=j+dy;
            if(x<0 || x==b.size() || y<0 || y==b[0].size() )continue;
            if(b[x][y]=='M')ret++;
        }
        return ret;
    }
    void dfs(int x,int y,vector<vector<char>>&b){
            if(x<0 || x==b.size() || y<0 || y==b[0].size() )return;
        if(b[x][y]!='E'){
            return;
        }
        int c=count(x,y,b);
        if(c==0){
            b[x][y]='B';
            for(auto [dx,dy]:dirs){
                dfs(x+dx,y+dy,b);
            }
        }
        else{
            b[x][y]='0'+c;
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& b, vector<int>& click) {
        if(b[click[0]][click[1]]=='M' ){
            b[click[0]][click[1]]='X';
            return b;
        }
        dfs(click[0],click[1],b);
        return b;
    }
};