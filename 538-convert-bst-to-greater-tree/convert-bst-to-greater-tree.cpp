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
    void inorder(TreeNode*root,vector<int>& in){
        if(!root)return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    void bfs(vector<int>& temp,vector<int>&in,TreeNode*r){
        if(!r)return;
        int i=lower_bound(in.begin(),in.end(),r->val)-in.begin();

        // for(;i<in.size();i++){
        //     if(r->val==in[i]){
        //         break;
        //     }
        // }
        r->val+=temp[i+1];
        bfs(temp,in,r->left);
        bfs(temp,in,r->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        vector<int> temp;
        temp=in;
        temp.push_back(0);
        for(int i=temp.size()-2;i>=0;i--){
            temp[i]+=temp[i+1];
        }
        bfs(temp,in,root);
        return root;        
    }
};