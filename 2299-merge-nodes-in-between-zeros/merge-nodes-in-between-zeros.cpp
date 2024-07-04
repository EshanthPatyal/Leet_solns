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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* cur=head;
        cur=cur->next;
        ListNode* ret=new ListNode();
        ListNode*temp=ret;
        while(cur){
            if(cur->val==0){
                ret->next=new ListNode(sum);
                sum=0;
                ret=ret->next;
                cur=cur->next;
            }
            else{
                sum+=cur->val;
                cur=cur->next;
            }
        }
        return temp->next;
    }
};