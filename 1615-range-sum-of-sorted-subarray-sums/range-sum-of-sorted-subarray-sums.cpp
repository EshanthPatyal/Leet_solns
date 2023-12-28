class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> v;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                sum%=mod;
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        long long ret=0;
        for(int i=left-1;i<right;i++){
            ret+=v[i];
            ret=ret%mod;
        }
        return ret;
    }
};