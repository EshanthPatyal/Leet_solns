class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        vector<int> v;
        for(auto it:bank){
            int c=0;
            for(auto it2:it){
                if(it2=='1'){
                    c++;
                }
            }
            if(c!=0)
                v.push_back(c);
        }
        if(v.size()<=1){
            return 0;
        }        
        int sum=0;
        for(int i=0;i<v.size()-1;i++){
            sum+=(v[i]*v[i+1]);

        }
        return sum;
    }
};