class Solution {
public:
    int minChanges(string s) {
        int out=0;
        for(int i=0; i<s.size(); i+=2)
            out+=(s[i]!=s[i+1]);
        return out;
    }
};