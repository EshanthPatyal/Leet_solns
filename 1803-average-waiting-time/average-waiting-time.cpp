class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double out=0;
        int time=c[0][0];
        for(auto it:c){
            if(time<it[0]){
                time=it[0];
            }
            time+=it[1];
            out+=(time-it[0]);
        }
        double n=(double)c.size();
        out/=n;
        return out;
        
    }
};