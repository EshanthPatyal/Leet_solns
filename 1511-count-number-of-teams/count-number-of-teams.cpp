class Solution {
public:
    int numTeams(vector<int>& v) {
        int ret=0;
        for(int i=0;i<v.size();i++){
            int leftsmall=0,leftlarge=0,rightsmall=0,rightlarge=0;
            for(int j=0;j<i;j++){
                if(v[j]<v[i])leftsmall++;
                if(v[j]>v[i])leftlarge++;
            }
            for(int j=i+1;j<v.size();j++){
                if(v[j]<v[i])rightsmall++;
                if(v[j]>v[i])rightlarge++;
            }
            ret+=(rightsmall*leftlarge + rightlarge*leftsmall);
        }
        return ret;
    }
};