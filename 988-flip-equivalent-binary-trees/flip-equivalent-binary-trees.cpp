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
    bool recur(TreeNode* r1,TreeNode* r2){
        if(!r1 && !r2)return true;
        if((r1 && !r2 ) || (r2&&!r1) || r1->val!=r2->val )return false;

        bool flip=recur(r1->left,r2->right) && recur(r1->right,r2->left);
        bool notflip=recur(r1->left,r2->left) && recur(r1->right,r2->right);
        return r1->val==r2->val && (flip || notflip); 
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return recur(root1,root2);
    }
};