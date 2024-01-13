class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count_s(26, 0),count_t(26, 0);

        for (char a : s) {
            count_s[a - 'a']++;
        }
        for (char a : t) {
            count_t[a - 'a']++;
        }

        int ret = 0;
        for (int i = 0; i < 26; i++) {
            ret += abs(count_s[i] - count_t[i]);
        }

        return ret / 2;          
    }
};