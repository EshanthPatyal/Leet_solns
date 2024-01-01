class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        vector<long long> pr(v.size()+1,1);
        vector<long long> su(v.size()+1,1);
        for(int i=1;i<pr.size();i++){
            pr[i]=pr[i-1]*v[i-1];
        }
        for(int i=v.size()-1;i>0;i--){
            su[i-1]=su[i]*v[i];
        }
        vector<int> ret(v.size(),1);
        ret[0]=su[0];
        for(int i=1;i<v.size();i++){
            ret[i]=pr[i]*su[i];
        }
        return ret;
    }
};