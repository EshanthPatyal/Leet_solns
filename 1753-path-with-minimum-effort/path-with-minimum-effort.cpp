class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int col=heights[0].size();
        int row=heights.size();
        vector<vector<int>> dist(row,(vector<int> (col,INT_MAX))); 
        dist[0][0]=0;
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>> ,greater<pair<int, pair<int, int>>>> st;
        st.push({0,{0,0}});
        list<pair<int,int>> dir ={{-1,0},{0,-1},{1,0},{0,1}};
        while(!st.empty()){
            int diff = st.top().first;
            int i = st.top().second.first;
            int j = st.top().second.second;
            st.pop();      
            if(i==row-1 && j==col-1)
                return diff;
                        
            for(auto& it: dir){
                if(i+it.first>=0 && i+it.first<row && j+it.second>=0 && j+it.second<col){
                    int a=heights[i][j]-heights[i+it.first][j+it.second];
                    a=abs(a);
                    a=max(a,diff);
                    if(dist[i+it.first][j+it.second]>a){
                        dist[i+it.first][j+it.second]=a;
                        st.push({a,{i+it.first,j+it.second}});
                    }
                }
            }
            
        }  
        return dist[row-1][col-1];
    }
};