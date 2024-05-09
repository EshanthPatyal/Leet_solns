class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.rbegin(),h.rend());
        long long out=0;
        
        for(int i=0;i<k;i++){
            out+=max(0,(h[i]-i));
            //cout<<out<<" "<<i<<" ";
        }
        return out;
    }
};