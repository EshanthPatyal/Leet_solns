class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        stack<char>st;
        int i=0,out=0;
        while(i<n){
            if(st.empty() || (s[i]!='a' && s[i]!='b'))st.push(s[i]);
            else if(s[i]=='a'){
                if(y>=x){
                    if(st.top()=='b'){
                        st.pop();
                        out+=y;
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            else if(s[i]=='b'){
                if(y<=x){
                    if(st.top()=='a'){
                        st.pop();
                        out+=x;
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            i++;
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        n=s.length();
        i=0;
       while(i<n){
            if(st.empty() || (s[i]!='a' && s[i]!='b'))st.push(s[i]);
            else if(s[i]=='a'){
                if(st.top()=='b'){
                    out+=y;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else if(s[i]=='b'){
                if(st.top()=='a'){
                    out+=x;
                    st.pop();
                }
                 else{
                    st.push(s[i]);
                }                
            }
            i++;
        }        
        return out;
        
    }
};