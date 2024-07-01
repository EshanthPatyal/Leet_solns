class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0;
        while(i+2<=arr.size()-1){
            if(arr[i]%2==1){
                if(arr[i+1]%2==1 && arr[i+2]%2==1){
                    return true;
                }
            }
            i++;
        }
        return false;
    }
};