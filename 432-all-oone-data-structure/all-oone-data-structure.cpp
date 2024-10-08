class AllOne {
public:
    unordered_map<string, int> freq;
    set<pair<int,string>> st;
    AllOne() {

    }
    
    void inc(string key) {
        st.erase({freq[key],key});
        freq[key]++;

        st.insert({freq[key], key});
    }
    
    void dec(string key) {
        st.erase({freq[key],key});
        freq[key]--;

        if(freq[key] > 0){
            st.insert({freq[key], key});
        }
    }
    
    string getMaxKey() {
        if(st.size()==0){return "";}
        string ans = prev(st.end())->second;
        return ans;
    }
    
    string getMinKey() {
        if(st.size()==0){return "";}
        string ans = st.begin()->second;
        return ans;
    }
};