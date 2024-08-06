class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> mp;
        vector<int> v(26,0);
        for(auto it:word){
            v[it-'a']++;
        }
        sort(v.rbegin(),v.rend());
        int i=1;
        for(auto it:v){
            mp[i]=it;
            i++;
        }
        int cur=0,t=0,out=0;
        for(auto it:mp){
            cur%=8;
            if(cur==0){
                t++;
            }
            out+=(it.second*t);
            cur++;
        }
        return out;
    }
};