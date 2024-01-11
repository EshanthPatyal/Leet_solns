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
    map<int,vector<int>> mp;
    void bst(TreeNode* root){
        if(!root)return;
            if(root->left!=NULL){
                mp[root->val].push_back(root->left->val);
                mp[root->left->val].push_back(root->val);
            }
            if(root->right!=NULL){
                mp[root->val].push_back(root->right->val);
                mp[root->right->val].push_back(root->val);
            }
            bst(root->left);
            bst(root->right);

    }
    int amountOfTime(TreeNode* root, int start) {
        bst(root);
        queue<int> q;
        int curr_time=0;
        set<int> s;
        q.push(start);
        while(!q.empty()){
            curr_time++;
            int a=q.size();
            while(a--){
                int it=q.front();
                q.pop();
                s.insert(it);
                for(int iter:mp[it]){
                    if(!s.count(iter)){
                        q.push(iter);
                    }
                }
            }
        }
        return curr_time-1;
    }
};