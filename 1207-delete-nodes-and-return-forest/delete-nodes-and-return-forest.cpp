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
    TreeNode* dfs(TreeNode*root,int i){
        if(!root)return NULL;
        if(root->val==i)return root;
        if(root->left && root->left->val==i){
            auto ret=root->left;
            root->left=NULL;
            return ret;
        }
        if(root->right && root->right->val==i){
            auto ret=root->right;
            root->right=NULL;
            return ret;
        }
        auto t=dfs(root->left,i);
        if(t!=NULL){
            return t;
        }
        t=dfs(root->right,i);
        return t;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        queue<TreeNode*> q;
        q.push(root);
        // dfs(ret,del,0,0);
        int i=0;
        while(i<del.size()){
            int curr=del[i];
            int a=q.size();
            while(a--){
                auto now=q.front();
                cout<<q.front()->val<<" ";
                auto temp=dfs(now,curr);
                if(now==temp){
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);   
                    q.pop();
                }
                else if(temp==NULL){
                    q.pop();
                    q.push(now);
                    continue;
                }
                else{
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);   
                    q.pop();
                    q.push(now);                 
                }
            }
            cout<<endl;
            i++;
        }
        vector<TreeNode*>ret;
        while(!q.empty()){
            if(q.front()!=NULL)ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};