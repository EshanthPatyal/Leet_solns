class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string>di;
        for(auto it:dictionary){
            di.insert(it);
        }
        string ret="";
        string word="";
        bool found=false;
        sentence+=' ';
        for(char c:sentence){
            if(c!=' '){
                    word+=c;
                if(!found && di.count(word)){
                    ret+=word;
                    found=true;
                }
            }
            else{
                if(!found)ret+=word;
                word="";
                ret+=' ';
                found=false;
            }
        }
        if(ret[ret.size()-1]==' ')return ret.substr(0,ret.size()-1);
        return ret;
    }
};