class Solution {
public:
    int minPatches(vector<int>& v, int n) {
        int o=0,i=0;
        long long curr=1;
        sort(v.begin(),v.end());
        // bool flag=true;
        while(curr<=n){
            // maxi+=v[i];
            if(i<v.size() && v[i]<=curr){
                curr+=v[i];
                i++;
            }
            else{
                curr*=2;
                o++;
            }
        }
        return o;
    }
};