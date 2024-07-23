class Solution {
public:
    bool doesAliceWin(string s) {
        int c=0;
        for(auto it:s){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u')c++;
            if(c>0)return true; 
        }
        // if(c==0)return false;
        return false;
    }
};