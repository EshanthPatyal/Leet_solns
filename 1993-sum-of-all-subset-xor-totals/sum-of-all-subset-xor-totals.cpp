class Solution {
public:
    void recur(long long&sum,vector<int>&v,int idx,int curr_xor){
        if(idx==v.size()){
            sum+=curr_xor;
            return;
        }

        recur(sum,v,idx+1,curr_xor);
        curr_xor^=v[idx];
        recur(sum,v,idx+1,curr_xor);
        return;

    }
    int subsetXORSum(vector<int>& v) {
        long long sum=0;int xor_1=0;
        recur(sum,v,0,xor_1);
        return sum;
    }
};