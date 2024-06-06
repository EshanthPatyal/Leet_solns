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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        auto t=head;
        while(t){
            n++;
            t=t->next;
        }
        int rem=n%k,siz=n/k;
        vector<ListNode*>ret; 
        t=head;
        if(siz==0){
            while(t){
                auto t1=t->next;
                t->next=NULL;
                ret.push_back(t);                
                t=t1;
            }
            while(ret.size()<k){
                ret.push_back({});
            }

        }
        while(t){
            ret.push_back(t);
            cout<<t->val;
            for(int i=1;i<siz;i++){
                t=t->next;
            }
            if(rem>0){
                t=t->next;
                rem--;
            }
            if(t){
                auto temp=t->next;
            t->next=NULL;
            t=temp;}
            // rem--;
        }
        return ret;
    }
};