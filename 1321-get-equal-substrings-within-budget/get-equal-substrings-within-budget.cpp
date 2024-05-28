class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> v;
        for(int i=0;i<s.length();i++){
            v.push_back(abs(s[i]-t[i]));
        }
        int i=0,j=0;
        int curr_max=0,ret=0,score=0;
        while(j<v.size()){
            score+=v[j];
            while(score>maxCost){
                score-=v[i];
                i++;
            }
            ret=max(ret,j-i+1);
            j++;
        }
        return ret;
    }
};