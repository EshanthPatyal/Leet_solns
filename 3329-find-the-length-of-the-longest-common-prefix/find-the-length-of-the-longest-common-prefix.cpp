class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string,int>mp;
        for(auto it:arr1){
            string t=to_string(it);
            string n="";
            for(auto it1:t){
                n+=it1;
                mp[n]++;
            }
        }
        int out=0;
        for(auto it:arr2){
            string t=to_string(it);
            string n="";
            for(auto it1:t){
                n+=it1;
                if(mp.find(n)!=mp.end()){
                    out=max(out,(int)n.length());
                }
            }
        }
        return out;
    }
};