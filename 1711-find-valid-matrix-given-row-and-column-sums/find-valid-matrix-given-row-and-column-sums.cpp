class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        priority_queue <pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > r,c;
        for(int i=0;i<row.size();i++){
            r.push({row[i],i});
        } 
        for(int i=0;i<col.size();i++){
            c.push({col[i],i});
        } 
        vector<vector<int>> ret(row.size(),vector<int>(col.size()));
        while(!r.empty() && !c.empty()){
            int ri = r.top().second;
            r.pop();
            int ci = c.top().second;
            c.pop();
            if(row[ri] < col[ci]){
                ret[ri][ci] = row[ri];
                col[ci] -= row[ri];
                row[ri] = 0;
                if(col[ci] > 0) 
                    c.push({col[ci], ci});
            } 
            else{
                ret[ri][ci] = col[ci];
                row[ri] -= col[ci];
                col[ci] = 0;
                if(row[ri] > 0) 
                    r.push({row[ri], ri});
            }
        }        
        return ret;


    }
};