class Solution {
public:
    string rev(string a){
        string s="";
        for(auto it:a){
            s+=(it=='1'?'0':'1');
        }
        reverse(s.begin(),s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        n--;
        for(int i=0;i<n;i++){
            string sn="1" + rev(s);
            s=s+sn;
        }
        return s[k-1];
    }
};