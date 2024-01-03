class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int arr1[10] = {};
        int arr2[10] = {};
        int n = secret.size(); // = guess.size()

        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                bull += 1;
            }
            else {
                arr1[secret[i] - '0'] += 1;
                arr2[guess[i] - '0'] += 1;
            }
        }

        int cow = 0;
        for (int i = 0; i < 10; ++i) {
            cow += min(arr1[i], arr2[i]);
        }
        
        string ret = "";
        ret += to_string(bull);
        ret += "A";
        ret += to_string(cow);
        ret += "B";
        return ret;
    }
};