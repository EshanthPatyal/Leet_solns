class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        map<int,int> mp;
        if(hand.size()%k!=0)return false;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        int ret=hand.size()/k;
        for(int i=0;i<v.size();i++){
            while(v[i].second!=0){
                v[i].second--;
                int siz=v.size();
                for(int j=i+1;j<=min(i+k-1,siz-1);j++){
                    if(v[j].second==0 || v[j-1].first+1!=v[j].first){
                        cout<<v[j].first<<" "<<v[j].second;
                        return false;
                    }
                    else{
                        v[j].second--;
                    }
                }
                ret--;
            }
            
        }
        return ret==0;

    }
};