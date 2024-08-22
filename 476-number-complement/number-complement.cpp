class Solution {
public:
    int findComplement(int num) {
        vector<int> v(32,0);
        for(int i=0;i<32;i++){
            if(num & (1<<i)){
                v[i]++;
            }
        }
        int out=0;
        bool flag=false;
        for(int i=31;i>=0;i--){
            if(v[i]==1){
                flag=true;
            }
            if(v[i]==0 && flag){
                out+=(1<<i);
            }
        }
        return out;
    }
};