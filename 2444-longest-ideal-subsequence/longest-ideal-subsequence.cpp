class Solution {
public:
    int longestIdealString(string s, int k) {
        int out=0;
        vector<int> v(26,0);

        for(int i=0;i<s.length();i++){
            int curr_ind=s[i]-'a';
            v[curr_ind]++;
            int beg=max(0,curr_ind-k);
            int end=min(25,curr_ind+k);
            int a=0;
            for(int j=beg;j<=end;j++){
                if(j!=curr_ind)
                    v[curr_ind]=max(v[curr_ind],1+v[j]);
            }

            out=max(out,v[curr_ind]);
        }
        return out;
    }
};