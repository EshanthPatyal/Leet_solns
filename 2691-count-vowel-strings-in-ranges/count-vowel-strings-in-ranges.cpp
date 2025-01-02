class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        int n=words.size();
        vector<int> ret,pref(n+1,0);
        set<char> t={'a','e','o','i','u'};
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i];
            if(t.count(words[i][0]) && t.count(words[i][words[i].length()-1])){
                pref[i+1]++;
            }
        }
        for(auto it:q){
            ret.push_back(abs(pref[it[0]]-pref[it[1]+1]));
        }
        return ret;
    }
};