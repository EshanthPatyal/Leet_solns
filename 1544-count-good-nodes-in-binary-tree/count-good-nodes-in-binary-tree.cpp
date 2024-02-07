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
    int a=0;
    int countNodes(TreeNode *root,int curr_max){
        if(!root){
            return a;
        }
        if(root->val>=curr_max){
            a++;
            curr_max=root->val;
        }
        countNodes(root->left,curr_max);
        countNodes(root->right,curr_max);
        return a;
    }
    int goodNodes(TreeNode* root) {
        int curr_max=root->val;
        return countNodes(root,curr_max);
    }
};