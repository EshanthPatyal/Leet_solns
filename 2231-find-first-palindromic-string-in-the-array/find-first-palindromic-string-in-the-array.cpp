class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string a=words[i];
            reverse(a.begin(),a.end());
            if(words[i]==a){
                return words[i];
            }
        }
        return "";
    }
};