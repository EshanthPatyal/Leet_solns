class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hfences, vector<int>& vfences) {
        hfences.push_back(1);
        hfences.push_back(m);
        vfences.push_back(1);
        long long mod=1000000007;
        vfences.push_back(n);
        sort(hfences.begin(),hfences.end()); 
        sort(vfences.begin(),vfences.end()); 
        set<int> s;
        for(int i=0;i<hfences.size();i++){
            for(int j=i+1;j<hfences.size();j++){
                s.insert(hfences[j]-hfences[i]);
            }   
        }
        long long num=-1; 
        for(int i=0;i<vfences.size();i++){
            for(int j=i+1;j<vfences.size();j++){
                long long a=(vfences[j]-vfences[i]);
                if(s.find(a)!=s.end()){
                    num=max(num,a);
                }
            }   
        }
        return num==-1?-1:(num*num)%mod;
    }
};