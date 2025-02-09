class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& v) {
        // sort(v.begin(), v.end(), [](auto &left, auto &right) {
        //                 return left[0] < right[0];
        //             });
        // for(auto it:v){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        vector<int>res(v.size(),0);
        map<int,int> node,color;
        if(v.size()>=1){
            res[0]=1;
            node[v[0][0]]=v[0][1];
            color[v[0][1]]++;
        }
        for(int i=1;i<v.size();i++){
            int curr_color=v[i][1],curr_node=v[i][0];
            if(node[curr_node]==0 && color[curr_color]==0){
                res[i]=res[i-1]+1;
            }
            else if(node[curr_node]!=0 && color[curr_color]!=0){
                if(node[curr_node]==curr_color){
                    res[i]=res[i-1];
                }
                else if(color[node[curr_node]]==1){
                    res[i]=res[i-1]-1;
                }
                else    res[i]=res[i-1];
                
            }
            else if(node[curr_node]!=0 && color[curr_color]==0){
                    if(color[node[curr_node]]==1){
                        res[i]=res[i-1];
                    }            
                else{
                    res[i]=res[i-1]+1;
                }
            }
            else{
                res[i]=res[i-1];
            }
            int old_col=node[curr_node];
            if(old_col){
                color[old_col]--;
            }
            node[curr_node]=curr_color;
            color[curr_color]++;
        }    
    
        return res;
    }
};