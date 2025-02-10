class Solution {
public:
    string clearDigits(string s) {
        stack<int> st;
        set<int> rem;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                if(!st.empty()){
                    int a=st.top();
                    st.pop();
                    rem.insert(a);
                    rem.insert(i);
                }
            }
            else st.push(i);
        }
        string ret="";
        for(int i=0;i<n;i++){
            if(rem.count(i)==0){
                ret+=s[i];
            }
        }
        return ret;

    }
};