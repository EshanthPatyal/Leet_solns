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
    long long out=0;
    int mod = 1e9+7;

    long long sum(TreeNode* root){
        if(!root){
            return 0;
        }
        long long a=root->val+sum(root->left)+sum(root->right);
        return a;
    }
    long long helper(TreeNode*root,long long sum){
        if(!root){
            return 0;
        }
        long long temp=helper(root->left,sum)+helper(root->right,sum)+root->val;
        long long temp2=(sum-temp)*temp;
        out=max(out,temp2);
        return temp;
    }
    int maxProduct(TreeNode* root) {
        long long ss = sum(root);        
        helper(root,ss);
        return out%mod;
    }
};