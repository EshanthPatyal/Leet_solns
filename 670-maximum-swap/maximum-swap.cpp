class Solution {
public:
    int maximumSwap(int num) {
        int curr=num;
        string s=to_string(num);
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                string t=s;
                swap(t[i],t[j]);
                curr=max(curr,stoi(t));
            }
        }
        return curr;
    }
};