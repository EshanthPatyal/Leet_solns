class Solution {
public:
    bool judgeSquareSum(int c) {
     map<long long,int> mp;
     for(long long i=1;i*i<=c+1;i++){
        mp[i*i]++;
     }   
     mp[0]++;
     for(auto it:mp){
        if(mp.find(c-it.first)!=mp.end()){
            return true;
        }
     }
     return false;
    }
};