class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& v) {
        sort(t.begin(),t.end());
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(t[i]!=v[i])return false;
        }
        return true;
    }
};