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
    void fun(TreeNode* root,vector<int>&temp) 
    {
        if (root == NULL) {
                return ;
            }
        
        fun(root->left,temp);
        temp.push_back(root->val);
        fun(root->right,temp);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        // st.push(root);
        auto curr=root;
        if(!root)return{};
        while(curr!=NULL ||!st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            v.push_back(curr->val);
            curr=curr->right;
        }
        return v;
    }
};