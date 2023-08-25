class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0;
        int j=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        int score=0;
        if(j==0){
            return power>=tokens[j]?1:0;
        }
        int flag=false;
        int ret=0;
        while(i<j){
            int a=i,b=j;
            //cout<<i<<" "<<j<<endl;
            if(score>0){
                score--;
                power+=tokens[j];
                j--;
            }
            while(i<=j && i<tokens.size()  && power-tokens[i]>=0){
                score++;
                power-=tokens[i];
                i++;

            }
            if(a==i && b==j){
                break;
            }
            ret=max(score,ret);

        }
        return ret;
    }
};