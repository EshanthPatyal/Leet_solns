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
        st.push(root);
        if(!root)return {};
        while(!st.empty()){
            auto t=st.top();
                st.pop();
            // st.pop();
            // else{
                if(t->right)st.push(t->right);
            // }
                if(t->left){
                    st.push(t->left);
                }            
                v.push_back(t->val);
        }
        return v;     
    }
};