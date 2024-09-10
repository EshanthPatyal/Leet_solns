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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p1=head;
        ListNode* p2=head->next;
        while(p2!=NULL){
            ListNode* temp=new ListNode(__gcd(p1->val,p2->val));
            p1->next=temp;
            temp->next=p2;
            p2=p2->next;
            p1=temp->next;
        }
        return head;
    }
};