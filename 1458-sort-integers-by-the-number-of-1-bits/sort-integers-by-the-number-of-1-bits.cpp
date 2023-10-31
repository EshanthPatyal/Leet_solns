class Solution {
public:
    static bool comp(int a,int b){
        int x,y;
        x=__builtin_popcount(a);
        y=__builtin_popcount(b);
        if(x==y){
            return a<b;
        }
        return x<y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),(comp));
        return arr;
    }
};