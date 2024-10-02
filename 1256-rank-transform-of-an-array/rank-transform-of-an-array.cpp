class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>  v;
        for(auto it:arr){
            v.insert(it);
        }
        int i=1;
        map<int,int> mp;
        for(auto it:v){
            mp[it]=i;
            i++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};