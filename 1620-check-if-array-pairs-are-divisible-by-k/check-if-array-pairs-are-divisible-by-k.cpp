class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> v(k,0);
        for(auto it:arr){
            v[((it)%k +k)%k]++;
        }
        int i=1;int j=k-1;
        if(v[0]%2==1)return false;
        while(i<j){
            if(i==j && v[i]%2!=0)return false;
            if(v[i]!=v[j])return false;
            i++;j--;
        }
        return true;
    }
};