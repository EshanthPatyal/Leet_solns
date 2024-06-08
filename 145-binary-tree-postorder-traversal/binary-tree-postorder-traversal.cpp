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
        fun(root->right,temp);
        temp.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        // fun(root,v);
        stack<TreeNode*>st;
              auto curr=root;
        if(!root)return{};
        while(curr!=NULL ||!st.empty()){
            while(curr){
                st.push(curr);
            v.push_back(curr->val);
                curr=curr->right;
            }
            curr=st.top();
            st.pop();
            curr=curr->left;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};