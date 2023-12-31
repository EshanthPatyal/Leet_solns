class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int> mp;
        int ret=-1;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(mp.find(c)==mp.end()){
                mp[c]=i;
            }
            else{

                ret=max(ret,i-mp[c]-1);
            }
        }
        return ret;
    }
};