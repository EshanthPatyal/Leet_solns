class Solution {
public:
    int longestSubarray(vector<int>& v, int l) {
        multiset<int> s;
        int i=0,j=0;
        while(j<v.size()){
            s.insert(v[j]);
            if(*s.rbegin()-*s.begin()>l){
                s.erase(s.find(v[i]));
                i++;
            }
            j++;
        }
        return j-i;
    }
};