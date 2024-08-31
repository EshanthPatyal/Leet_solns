class Solution {
public:
    long long minDamage(int p, vector<int>& d, vector<int>& h) {
        priority_queue<pair<long double,int>> pq;
        long long out=0,sum=0;
        vector<long long> req;
        for(int i=0;i<d.size();i++){
            long long time = h[i]/p + ((h[i]%p)>0);
            req.push_back(time);
            long double dam=(1.0*d[i])/(1.0*time);
            pq.push({dam,i});
            sum+=d[i];
        }   
        while(!pq.empty()){
            auto [dam,i] = pq.top();
            pq.pop();
            out += 1LL*sum*(req[i]);
            sum -= d[i];
        }
        return out;        
    }
};