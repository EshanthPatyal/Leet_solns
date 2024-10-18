class Solution {
public:
    long long c;
    int f(int i,int curr,vector<int>&v){
        if(i<0)return curr==c?1:0;

        int s=f(i-1,curr,v);
        int t=f(i-1,curr|v[i],v);
        return s+t;
    }
    int countMaxOrSubsets(vector<int>& v) {
        for(auto it:v)c=c|it;
        return f(v.size()-1,0,v);
    }
};