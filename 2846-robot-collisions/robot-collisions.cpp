class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        vector<pair<int,int>> v;
        int n=h.size();
        for(int i=0;i<n;i++){
            v.push_back({pos[i],i});
        }
        sort(v.rbegin(),v.rend());
        stack<int> st;
        for(int j=0;j<n;j++){
            int cur_pos=v[j].first;
            int i=v[j].second;
            if(d[i]=='L')st.push(i);
            else{
                while(!st.empty() && h[i]>0){
                    int cur_idx=st.top();
                    int dif=h[cur_idx]-h[i];
                    if(dif>0){h[cur_idx]--;h[i]=0;}
                    else if(dif<0){h[cur_idx]=0;h[i]--;st.pop();}
                    else {h[cur_idx]=0;h[i]=0;st.pop();}
                }
            }
        }
        vector<int> ret;
        for(auto it:h)if(it>0)ret.push_back(it);
        return ret;
    }
};