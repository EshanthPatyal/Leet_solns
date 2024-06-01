class Solution {
public:
    int scoreOfString(string s) {
        int out=0;
        for(int i=0;i<s.length()-1;i++){
            out+=abs(s[i+1]-s[i]);
        }   
        return out;
    }
};