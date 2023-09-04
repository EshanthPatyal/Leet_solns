/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
           int count=0;
        ListNode* temp=head;
        while(temp!=NULL && count <=10000 ){
            count++;
            temp=temp->next;
        }
        if(count>10000){
            return true;
        }
        return false;
    }
};