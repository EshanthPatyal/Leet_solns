class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int,int>> v;
        int n=p.size();
        for (int i = 0; i < n; i++) {
            v.push_back({-g[i],p[i]});//sorting by largest -ve g and smallest p
        }        
        int res=0,curr=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            res=max(res, curr+v[i].second - v[i].first);
            curr+=v[i].second;
        }
        return res;

    }
};