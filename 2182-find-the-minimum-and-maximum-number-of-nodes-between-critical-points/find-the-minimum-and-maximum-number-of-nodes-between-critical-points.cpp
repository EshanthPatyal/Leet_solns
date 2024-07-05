/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        int curr=0;
        ListNode* t=head;
        ListNode*prev=NULL;
        while(t){
            if(prev && prev->val<t->val){
                if(t->next && t->next->val<t->val){
                    v.push_back(curr);
                }
            }            
            if(prev && prev->val>t->val){
                if(t->next && t->next->val>t->val){
                    v.push_back(curr);
                }
            }
            curr++;
            prev=t;
            t=t->next;
        }
        if(v.size()<2){
            return {-1,-1};
        }
        int a=v[v.size()-1]-v[0];
        int b=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            b=min(v[i+1]-v[i],b);
        }
        return {b,a};
    }
};