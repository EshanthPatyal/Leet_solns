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
    ListNode * removeNodes(ListNode *head){
        stack<ListNode*> mono;
        auto temp=head;
        map<ListNode*,int> mp;
        ListNode* ret=new ListNode(-1,head);
        while(temp){
            auto a=temp->val;
            while(!mono.empty() && mono.top()->val<a){
                mp[mono.top()]++;
                mono.pop();
            }
            mono.push(temp);
            temp=temp->next;
        }
        // for(auto it:mp){
        //     cout<<it.first<<" ";
        // }
        temp=ret;
        while(temp->next){
            auto a=temp->next;
            if(mp.find(a)!=mp.end()){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return ret->next;
    }
};