class Solution {
public:
    vector<vector<string>> ret;
    void recur(string s,int idx,string curr,vector<string> v){
        if(idx==s.size()){
            if(curr.size()==0){
                ret.push_back(v);
            }
            v.clear();
            return ;
        }

        curr+=s[idx];
        string temp=curr;
        reverse(temp.begin(),temp.end());

        if(curr==temp){
            string n="";
            v.push_back(curr);
            recur(s,idx+1,n,v);
            v.pop_back();
        }
        reverse(temp.begin(),temp.end());

        recur(s,idx+1,temp,v);

        return ;

    }
    vector<vector<string>> partition(string s) {
        string tmp="";
        // tmp+=s[0];
        vector<string> v;
        recur(s,0,tmp,v);
        return ret;

    }
};