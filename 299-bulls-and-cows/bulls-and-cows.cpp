class Solution {
public:
    string getHint(string s, string g) {
        int c=0;
        map<char,int> mp1,mp2;
        for(int i=0;i<s.length();i++){
            if(s[i]==g[i])  c++;
            else{
                mp1[s[i]]++;
                mp2[g[i]]++;
            }
        }
        int a=0;
        for(auto it:mp2){
            auto temp=mp1.find(it.first);
            if(temp!=mp1.end()){
                a+=min(it.second,temp->second);
                it.second=0;
            }
        }
        string fir,sec;
        fir=to_string(c);
        sec=to_string(a);
        string ret=fir;
        ret+='A';
        ret+=sec;
        ret+='B';
        return ret;
    }
};