class Solution {
public:
    int minimumLength(string s) {
        vector<int>v(26,0);
        int n=s.length();
        for(auto it:s){
            v[it-'a']++;
        }
        int rem=0;
        for(int i=0;i<26;i++){
            if(v[i]>2){
                rem+=v[i]-(2-v[i]%2);
            }
        }
        return n-rem;
    }
};