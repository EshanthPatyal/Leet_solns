class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int bcount=s[0]=='b',acount=0;
        for(auto it:s)if(it=='a')acount++;
        int ret=bcount+acount-1;
        for(int i=1; i<n; i++){
            bcount+=(s[i]=='b');
            acount-=(s[i-1]=='a');
            ret=min(ret, bcount+acount-1);
        }
        return ret;        
    }
};