class Solution {
public:
    bool check(vector<int>& v,int i,int j,int k,vector<int>& arr){
        int l=v[j]^v[i];
        int r=v[j]^v[k+1];
        return l==r;
    }
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> v(n+1,0);
        v[1]=arr[0];
        for(int i=1;i<n;i++){
            v[i+1]=v[i]^arr[i];
        }
        int out=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    if(check(v,i,j,k,arr)){
                        out++;
                    }
                }
            }
        }
        return out;

    }
};