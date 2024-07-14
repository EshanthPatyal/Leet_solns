class Solution {
public:
    long cur=0;
    bool recur(vector<int>&m,int l1,int l2,int l3,int l4,int i){
        if(i==m.size()){
            if(l1==l2 && l2==l3 && l3==l4){
                return 1;
            }
            return 0;
        }
        if(l1>cur || l2>cur || l3>cur || l4>cur)return false;
        return recur(m,l1+m[i],l2,l3,l4,i+1) || recur(m,l1,l2+m[i],l3,l4,i+1)
                || recur(m,l1,l2,l3+m[i],l4,i+1) || recur(m,l1,l2,l3,l4+m[i],i+1);
    }
    bool makesquare(vector<int>& m) {
        int l1=0,l2=0,l3=0,l4=0,i=0;
        long long sum=0;
        for(auto it:m)sum+=it;
        if(sum%4!=0)return false;
        sort(m.rbegin(),m.rend());
        cur=sum/4;
        return recur(m,l1,l2,l3,l4,i);
    }
};