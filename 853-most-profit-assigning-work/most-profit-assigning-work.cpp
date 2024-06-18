class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> v;
         sort(worker.begin(),worker.end());
        for(int i=0;i<profit.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }
        int sum=0;
        sort(v.begin(),v.end());
        int maxProfit = 0;
        int tempprofit = 0;
        int n=worker.size();
        for( int i = 0 , j = 0 ; i < n ; i++ ){
            while(j<n && v[j][0] <= worker[i]){
                tempprofit = max(v[j][1],tempprofit);    
                j++;
            }
            if(j>0 && v[j-1][0]<=worker[i])
                maxProfit += tempprofit;
        }

        return maxProfit;
    }
};