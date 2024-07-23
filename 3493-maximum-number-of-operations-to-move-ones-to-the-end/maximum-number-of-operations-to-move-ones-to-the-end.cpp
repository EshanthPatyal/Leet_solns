class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int out=0,i=n-1,cur=0;
        while(i>=0){
            if(s[i]=='0'){
                cur++;
                while(i>=0 && s[i]=='0'){
                    i--;
                }
            }
            if(i>=0 && s[i]=='1'){
                i--;
                out+=cur;
            }
        }
        return out;
    }
};