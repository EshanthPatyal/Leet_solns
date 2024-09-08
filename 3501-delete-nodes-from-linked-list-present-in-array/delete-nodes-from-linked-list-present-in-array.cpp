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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> v(1e5+10,0);
        ListNode* ret=new ListNode();
        ListNode*t=ret;
        for(auto it:nums)v[it]++;
        ListNode*temp=head;
        while(temp){
            if(v[temp->val]==0){
                t->next=new ListNode(temp->val);
                t=t->next;
            }
            temp=temp->next;
        }
        return ret->next;
    }
};