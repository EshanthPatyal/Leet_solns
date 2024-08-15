class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,te=0,tw=0;
        for(auto it:bills){
            if(it==5)f++;
            if(it==10){
                if(f==0)return false;
                f--;
                te++;
            }
            if(it==20){
                if(te==0){
                    if(f<3)return false;
                    f-=3;
                    tw++;
                    continue;
                }    
                else if(f==0)return false;    
                f--;
                te--;
                tw++;
            }
        }
        return true;
    }
};