class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long>pq;
        if(target.size()==1 ){
            return target[0]==1;
        }
        long long sum=0;
        for(auto it:target){
            pq.push(it);
            sum+=it;
        }
        while(!pq.empty()){
            int curr=pq.top();
            pq.pop();
            sum-=curr;
            if(curr==1)continue;
            if(curr<sum || sum<0)return false;
            int rem=curr%sum;
            if(rem==0){
                rem+=sum;
                if(rem==curr)return false;
                pq.push(rem);
                sum+=rem;
            }
            else{
                pq.push(rem);
                sum+=rem;
            }
        }
        return true;
    }
};