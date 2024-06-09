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
    bool check(TreeNode* r1,TreeNode*r2){
        if(r1==NULL && r2==NULL)return true;
        if(r1==NULL||r2==NULL)return false;
        return r1->val==r2->val && check(r1->left,r2->left) && check(r1->right,r2->right);
    }
    bool recur(TreeNode* r1,TreeNode*r2){
        if(!r2)return true;
        if(!r1)return false;
        if(check(r1,r2)){
            return true;
        }
        return recur(r1->left,r2) || recur(r1->right,r2);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return recur(root,subRoot);
    }
};