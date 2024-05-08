class Solution {
public:

    vector<string> findRelativeRanks(vector<int>& score) {

        vector<pair<int,int>> v;
        for(int i=0;i<score.size();i++){
            v.push_back({score[i],i});
        }
        vector<string> ret(score.size());
        sort(v.rbegin(), v.rend());
        ret[v[0].second]="Gold Medal";
        if(score.size()==1)return ret;
        ret[v[1].second]="Silver Medal";
        if(score.size()==2)return ret;
        ret[v[2].second]="Bronze Medal";
        for(int i=3;i<score.size();i++){
            ret[v[i].second]=to_string(i+1);
        }
        return ret;
    }
};