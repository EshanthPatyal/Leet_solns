class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k, int k2) {
        long long out=0;
        int n=nums1.size();
        unordered_map<long long , long long>mp;
        for(int i=0;i<n;i++){
            mp[abs(nums1[i]-nums2[i])]++;
            out+=abs(nums1[i]-nums2[i]);
        }
        priority_queue<long long>   pq;
        for(auto it:mp){
            if(it.first>0){
                pq.push(it.first);
            }
        }
        k+=k2;
        if(k>=out)return 0;

        while(k && !pq.empty()){
            int curr=pq.top();
            int count=mp[curr];
            if(count<=k){
                mp.erase(curr--);
                pq.pop();
                k-=count;
                if(mp.find(curr)==mp.end())pq.push(curr);
                mp[curr]+=count;
            }
            else{
                mp[--curr]+=k;
                if(mp.find(curr)==mp.end())pq.push(curr);
                mp[++curr]-=k;
                k=0;
            }
        }
    
        long long ans = 0;
        
        for(auto it:mp){
            ans+=it.first*1LL*it.first*1LL*it.second;   
        }
        return ans;        

    }
};