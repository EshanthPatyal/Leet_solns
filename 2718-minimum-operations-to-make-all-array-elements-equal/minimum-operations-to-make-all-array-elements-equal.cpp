class Solution {
public:
    vector<long long> minOperations(vector<int>& v, vector<int>& queries) {
        sort(v.begin(), v.end());
        long long out = 0;
        int n=v.size();
        vector<long long> pre(n + 1), suf(n + 1), ret;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + v[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + v[i];
        }
        for (auto it : queries) {
            long long d = lower_bound(v.begin(), v.end(), it) - v.begin();
            long long ans = (d * it - pre[d]) + (suf[d] - (n - d) * it);
            ret.push_back(ans);
        }
        return ret;
    }
};