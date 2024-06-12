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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int curr=1;
        bool islast=false;
        while(!q.empty()){
            int a=q.size();
            if(a!=curr){
                if(islast==true)return false;
                islast=true;
            }
            int lastleaf=false;
            for(int i=0;i<a;i++){
                auto temp=q.front();
                q.pop();
                if(temp->left==NULL && temp->right!=NULL)return false;
                // if(temp->left!=NULL && temp->right==NULL && i!=a-1){cout<<i<<" "<<a;return false;}
                if(temp->left!=NULL){
                    if(lastleaf)return false;
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    if(lastleaf)return false;
                    q.push(temp->right);
                }
                if(temp->left==NULL || temp->right==NULL){
                    lastleaf=true;
                }
            }
            curr*=2;
        }  
        return true;
    }
};