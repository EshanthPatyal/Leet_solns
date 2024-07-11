class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n=s.length();
        vector<int> v(n,-1),curr;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                curr.push_back(i);
            }
            else if(s[i]==')'){
                int j=curr.back();
                curr.pop_back();
                v[i]=j;
                v[j]=i;

            }
        }
        string ret="";
        int cur_step=1;
        for(int i=0;i<n;i+=cur_step){
            if(s[i]=='(' || s[i]==')'){
                i=v[i];
                cur_step*=-1;
            }
            else{
                ret+=s[i];
            }
        }
        return ret;
    }
};