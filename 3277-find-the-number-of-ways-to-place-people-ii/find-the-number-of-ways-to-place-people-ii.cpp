class Solution {
public:
    static bool comp(pair<int,int>&a, pair<int,int>& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    };
    int numberOfPairs(vector<vector<int>>& points) {
        vector<pair<int,int>> pts;
        for(auto it:points){
            pts.push_back({it[0],it[1]});
        }
        sort(pts.begin(),pts.end(),comp);
        int n=pts.size(),out=0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1, y = INT_MIN; j < n; j++){
                if (pts[i].second >= pts[j].second && y < pts[j].second) {
                    ++out;
                    y = pts[j].second;
                }
            }
        }   
        return out;
    }
};