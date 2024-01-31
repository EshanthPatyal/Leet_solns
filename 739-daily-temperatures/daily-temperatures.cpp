class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums2) {
        stack<int> mono;
        map<int,int> v;
        vector<int> ret(nums2.size(),0);
        for(int i=0;i<nums2.size();i++){
            while(mono.empty()==false && nums2[mono.top()]<nums2[i] ){
                v[mono.top()]=i;
                mono.pop();
            }
            mono.push(i);
        }      
        for(int i=0;i<nums2.size();i++){
            if(v[i]>0){
                ret[i]=v[i]-i;
            }
            else{
                ret[i]=0;
            }
        }
        return ret;
    }
};