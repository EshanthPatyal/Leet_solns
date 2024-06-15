class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            vector<pair<int,int>> v;
            long long int curr_cap=w;
            priority_queue <int> pq;
            for(int i=0;i<profits.size();i++){
                v.push_back({capital[i],profits[i]});
            }
            sort(v.begin(), v.end());
            int i=0;
            while(k--){
                while(i<profits.size() && curr_cap>=v[i].first){
                    pq.push(v[i].second);
                    i++;
                }
                if(!pq.empty()){
                    curr_cap+=pq.top();
                    pq.pop();
                }
                else{
                    break;
                }
            }
            return curr_cap;
    }
};