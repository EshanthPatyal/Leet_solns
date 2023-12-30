class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int> mp;
        if (words.size()==1) return true;
        for(auto it: words){
            for(int i=0;i<it.length();i++){
                mp[it[i]]++;
            }
        }
        for(auto it:mp){
            if (it.second%words.size()!=0) return false;
        }
        return true;
    }
};