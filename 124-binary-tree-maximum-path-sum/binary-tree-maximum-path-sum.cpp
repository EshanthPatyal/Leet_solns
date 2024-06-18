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
    int sum=INT_MIN;
    int recur(TreeNode* root){
        if(!root)return 0;
        int l=recur(root->left);
        l=max(0,l);
        
        int r=recur(root->right);
        r=max(0,r);
        sum=max(sum,root->val+l+r);

        return max(l,r)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        recur(root);
        return sum;
    }
};