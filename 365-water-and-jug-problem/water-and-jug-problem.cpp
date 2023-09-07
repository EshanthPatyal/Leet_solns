class Solution {
public:
    bool helper(int x,int y,int t,int curr,map<int,int>& vis){
        if(t==curr) return true;
        if(curr<0 || vis[curr] ||curr>x+y) return false;
        vis[curr]=true;
        return helper(x,y,t,curr+x,vis)||helper(x,y,t,curr-x,vis)||helper(x,y,t,curr+y,vis)||helper(x,y,t,curr-y,vis);
    }
    bool canMeasureWater(int x, int y, int test) {
        map<int,int> mp;
        return helper(x,y,test,0,mp);

    }
};