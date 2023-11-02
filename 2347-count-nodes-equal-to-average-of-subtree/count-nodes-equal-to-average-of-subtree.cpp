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
    int ret=0;
    int num=0;
    int sum_subtree(TreeNode* root){
        if(!root)   return 0;
        num++;
        return root->val+sum_subtree(root->left)+sum_subtree(root->right);
    }
    void count(TreeNode* root){
        if(!root) return;
        num=0;
        int temp=sum_subtree(root);
        if(temp/num==root->val){
            ret++;
        }
        num=0;
        count(root->left);
        count(root->right);
        return ;
    }
    int averageOfSubtree(TreeNode* root) {
        count(root);
        return ret;
        
    }
};