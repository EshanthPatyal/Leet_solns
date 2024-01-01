class Solution {
public:

    int countPrimes(int n) {
        int c= 0;
        vector<bool>v(n+1,true);
        v[0]=v[1]=0;
        for(int i =2;i<n;i++)
        {
            if(v[i])
            {
                c++;
                for(int j = 2*i;j<n;j=j+i)
                {
                    v[j]=false;
                }
            }
        }
        return c;

    }
};