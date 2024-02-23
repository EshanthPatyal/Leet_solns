class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,list<pair<int,int>>> mp;
        for(int i=0;i<flights.size();i++){
            mp[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        vector<int> dist(n,INT_MAX);
        queue<vector<int>> st;
        dist[src]=0;
        st.push({0,src,0});
        while(!st.empty()){
            auto front=st.front();
            st.pop();
            for(auto neighbour: mp[front[1]]){
                if(front[2]<=k&&front[0]+neighbour.second<dist[neighbour.first]){
                    dist[neighbour.first]=front[0]+neighbour.second;
                    st.push({dist[neighbour.first],neighbour.first,front[2]+1});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};