class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(auto it:logs){
            if(it[0]=='.' && it[1]=='.'){
                count--;
                if(count<0)count=0;
            }
            else if(it[0]=='.'){
                continue;
            }
            else{
                count++;
            }
        }
        return count;
    }
};