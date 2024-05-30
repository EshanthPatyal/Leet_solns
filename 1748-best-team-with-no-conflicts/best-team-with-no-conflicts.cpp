class Solution {
public:
    static bool  comp(pair<int,int>& a,pair<int,int>& b){
                if (a.first != b.first)
                    return (a.first < b.first);
                else
                return (a.second < b.second);  
            }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        for(int i=0;i<ages.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end(),comp);
        int out = 0;
        int n=v.size();
        vector<int> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i] = v[i].second;
            
            for (int j = i - 1; j >= 0; --j) 
                if (v[i].second >= v[j].second)
                    dp[i] = max(dp[i], dp[j] + v[i].second);
            
            out = max(out, dp[i]);
        }

        return out;        
    }
};