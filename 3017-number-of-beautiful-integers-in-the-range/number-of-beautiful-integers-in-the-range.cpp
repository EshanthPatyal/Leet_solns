class Solution {
public:
    int dp[12][2][2][11][11][30];
    int recur(int idx,bool tight,int sum,int even,int odd,bool zero,string s,int k){
        if(idx==s.length()){
            if(sum%k==0 && even==odd)return 1;
            return 0;
        }
        if(dp[idx][tight][zero][even][odd][sum]!=-1){
            return dp[idx][tight][zero][even][odd][sum];
        }
        int cur=s[idx]-'0';
        if(!tight){
            cur=9;
        }
        int ans=0;
        for(int i=0;i<=cur;i++){
            int neven=even,nodd=odd;
            bool nzero=false,ntight=false;

            if(tight&&(i==cur))ntight=true;
            if((i==0) && zero)nzero=true;
            if((i!=0 || !zero) && i%2==0){neven++;}
            else if((i!=0 || !zero) && i%2==1){nodd++;}
      
            int ad=i*pow(10,s.length()-idx-1);
            ad=ad%k;
            ans+=recur(idx+1,ntight,(sum+ad)%k,neven,nodd,nzero,s,k);
        }
        return dp[idx][tight][zero][even][odd][sum]=ans;
        
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1 = to_string(low - 1);
        string s2 = to_string(high);
        memset(dp, -1, sizeof(dp));
        int ans1 = recur(0, true, 0, 0, 0, true, s1,k);
        memset(dp, -1, sizeof(dp)); 
        int ans2 = recur(0, true, 0, 0, 0, true, s2,k);
        return ans2 - ans1;

    }
};