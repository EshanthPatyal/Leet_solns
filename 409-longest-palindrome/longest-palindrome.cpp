class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(200,0);
        for(auto it:s){
            v[it]++;
        }
        int out=0,o=0;
        for(auto it:v){
            if(o==0 && it%2==1)o++;
            if(it>=2){
                out+=(it-it%2);
            }
        }
        return out+o;
    }
};