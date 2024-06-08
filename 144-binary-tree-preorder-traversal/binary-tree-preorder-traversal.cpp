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
        temp.push_back(root->val);        
        fun(root->left,temp);
        fun(root->right,temp);        

    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> v;
        stack<TreeNode*> st;
        auto curr=root;
        if(!root)return {};
        while(curr!=NULL ||!st.empty()){
            while(curr){
                st.push(curr);
            v.push_back(curr->val);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            curr=curr->right;
        }
        return v;     
    }
};