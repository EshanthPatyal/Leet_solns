class Solution {
public:
    int calc_score(string w,vector<int> freq, vector<int>& score){
        int s=0;
        for(auto it:w){
            freq[it-'a']--;
            if(freq[it-'a']<0){
                return 0;
            }
            else{
                s+=score[it-'a'];
            }
        }
        return s;

    }
    int maxi=0;
    void recur(vector<string>& words, vector<int>& freq, vector<int>& score,int i,string w){
        if(i>=words.size()){
            return ;
        }
        string t=w;
        t+=words[i];
        int scor=calc_score(t,freq,score);
        if(scor!=0){
            maxi=max(maxi,scor);
        }
        recur(words,freq,score,i+1,w);
        recur(words,freq,score,i+1,t);
        return ;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        for(auto it:letters){
            freq[it-'a']++;
        }
        recur(words,freq,score,0,"");
        return maxi;
    }
};