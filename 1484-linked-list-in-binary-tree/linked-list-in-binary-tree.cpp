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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;vector<TreeNode*>ch;
    bool check(int i,TreeNode*curr){
        if(i==v.size())return true;
        if(curr==NULL)return false;
        bool a=false;
        if(curr->val==v[i]){
            return check(i+1,curr->left) || check(i+1,curr->right);
        }
        return false;
    }
    void dfs(TreeNode*curr){
        if(!curr)return;
        if(curr->val==v[0]){
            ch.push_back(curr);
        }
        dfs(curr->left);
        dfs(curr->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        auto curr=head;
        while(curr){
            v.push_back(curr->val);
            curr=curr->next;
        }
        // return check(0,root);
        dfs(root);
        for(auto it:ch){
            if(check(0,it)){
                return true;
            }
        }
        return false;
    }
};