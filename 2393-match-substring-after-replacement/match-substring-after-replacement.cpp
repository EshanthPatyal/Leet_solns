class Solution {
public:
        map<char,map<char,char>>mp;
    bool f(string s,int idx,string s2){
        if(idx+s2.size()>s.size())return false;
        int j=0;
        for(int i=idx;i<idx+s2.size();i++){
            if(s2[j]==s[i] || mp[s2[j]][s[i]]){
                j++;
            }
            else return false;
        }
        return true;
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        for(auto it:mappings){
            mp[it[0]][it[1]]=1;
        }
        for(int i=0;i<s.size();i++){
            if(f(s,i,sub))return true;
        }
        return false;

    }
};