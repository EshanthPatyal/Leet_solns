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
    TreeNode* recur(vector<int>&v,int i,int n){
        if(i>n){
            return NULL;
        }
        int mid=(i+n)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=recur(v,i,mid-1);
        root->right=recur(v,mid+1,n);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums,0,nums.size()-1);
    }
};