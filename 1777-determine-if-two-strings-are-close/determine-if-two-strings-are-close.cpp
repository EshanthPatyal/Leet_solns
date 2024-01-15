class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())return 0;
        vector<int>s,s1;
        map<char,int> m1,m2;
        for(auto it:word1){
            m1[it]++;
        }
        for(auto it:word2){
            if(m1.find(it)==m1.end()){
                return false;
            }
            m2[it]++;
        }
        for(auto it:m1){
            s.push_back(it.second);
        }
        for(auto it:m2){
            s1.push_back(it.second);
        }
        sort(s.begin(),s.end());
        sort(s1.begin(),s1.end());
        if(s.size()!=s1.size()) return 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s1[i])return 0;
        }

        return 1;
    }
};