class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int out=0;
        set<string> st;
        vector<int>l(26,0);
        vector<int>r(26,0);
        vector<int>allsame(26,0);
        l[s[0]-'a']++;
        int n=s.length();
        for(int i=1;i<n;i++)r[s[i]-'a']++;
        for(int i=1;i<n-1;i++){
            r[s[i]-'a']--;
            for(int j=0;j<26;j++){
                if(l[j]>0 && r[j]>0){
                    char c='a';
                    string temp="";
                    c+=j;
                    temp+=c;
                    temp+=s[i];
                    temp+=c;
                    st.insert(temp);
                }
            }
            l[s[i]-'a']++;
        }
        return st.size();
    }
};