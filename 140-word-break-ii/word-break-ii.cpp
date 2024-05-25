class Solution {
public:
    vector<string> ret;
    void recur(string s,int idx,string curr,set<string>& uniq){
        if(idx>=s.length()){
            ret.push_back(curr);
            return ;
        }
        string t="";
        for(int i=idx;i<s.length();i++){
            t+=s[i];
            if(uniq.find(t)!=uniq.end()){
                string temp=curr;
                temp+=t;
                if(i<s.length()-1){
                    temp+=" ";
                }
                recur(s,i+1,temp,uniq);
            }
        }
        return ;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> uniq;
        for(auto it:wordDict){
            uniq.insert(it);
        }
        recur(s,0,"",uniq);
        return ret;
    }
};