class Solution {
public:
    long long maximumTotalSum(vector<int>& v) {
        sort(v.rbegin(),v.rend());
        long long out=0;
        int pre = INT_MAX;
        for (auto it:v) {
            int curr=min(it,pre-1);
            if(curr==0)return -1;
            out+=curr;
            pre=curr;
        }
        return out;        
    }
};