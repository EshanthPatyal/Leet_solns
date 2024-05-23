class Solution {
public:

    int recur(vector<int>&v,int i,vector<int>&c,int k){
        if(i>=v.size()){
            return 0;
        }
        bool a=true,b=true;
        int count=0;
        if(v[i]-k>0){
            a=c[v[i]-k]==0;
        }
        if(v[i]+k<=1000){
            b=c[v[i]+k]==0;
        }
        if(a&&b){
            c[v[i]]++;
            count+=1+recur(v,i+1,c,k);
            c[v[i]]--;
        }
        return count+recur(v,i+1,c,k);


    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> count(1001,0);
        return recur(nums,0,count,k);
    }
};