class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,out=0;
        vector<int> v(1300,0);
        if(!s.length()){
            return 0;
        }
        while(j<s.length()){
            if(v[s[j]]==0){
                v[s[j]]++;
                out=max(out,j-i+1);
                cout<<j<<" "<<i<<endl;
                j++;
            }
            else{
                while(i<j && s[i]!=s[j]){
                    v[s[i]]--;
                    i++;
                }
                i++;
                j++;
            }
        }
        return out;
    }
};