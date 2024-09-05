class Solution {
public:
// x= 1xor2xor....n

// enc1 = per[1 xor per[2
// enc3 = per[3 xor per[4
// per[0 = x xor enc1 xor enc2 .....  
    vector<int> decode(vector<int>& encoded) {
        int x=0;
        int n=encoded.size()+1;
        for(int i=1;i<=n;i++)x=x^i;

        for(int i=1;i<n;i+=2){
            x=x^encoded[i];
        }
        vector<int> res;
        res.push_back(x);
        for (int it:encoded) {
            res.push_back(res.back() ^ it);
        }
        return res;
    }
};