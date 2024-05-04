class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int curr_count=0;
        int i=0,j=people.size()-1;
        sort(people.begin(),people.end());
        while(i<=j){
            if(i==j){
                curr_count++;
                i++;
                j--;
            }
            else{
                if(people[j]+people[i]<=limit){
                    curr_count++;
                    i++;
                    j--;
                }
                else{
                    curr_count++;
                    j--;
                }
            }
        }
        return curr_count;
    }
};