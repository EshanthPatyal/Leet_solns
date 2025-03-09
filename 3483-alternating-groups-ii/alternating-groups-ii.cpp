class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& v, int k) {
        int out=0;
        int n=v.size();
        // vector<int> pre(2*n+1,0);
        int i=0,j=1;
        while(i<n){
            if(v[j%n]==v[(j-1)%n]){
                i=j;
                j++;
            }
            else{
                if(j-i+1==k){
                    out++;
                    i++;
                }
                j++;
            }
        }
        return out;

    }
};