class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int>mp;
        string v="aeiou";
        mp[0]=-1;
        int mask=0,res=0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<v.length();j++){
                if(s[i]==v[j]){
                    mask^=(1<<j);
                    break;
                }
            }
            if(mp.find(mask)==mp.end()){
                mp[mask]=i;
            }
            res=max(res,i-mp[mask]);
        }
        return res;
    }
};