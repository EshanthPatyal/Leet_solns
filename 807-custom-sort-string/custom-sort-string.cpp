class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26,0);
        for(auto it:s ){
            v[it-'a']++;
        }
        string ret="";
        for(auto it:order){
            while(v[it-'a']>0){
                ret+=it;
                v[it-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            while(v[i]>0){
                char c='a'+i;
                ret+=c;
                v[i]--;
            }
        }
        
        return ret;
    }
};