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
    int out=0;
    bool check(map<int,int> &mp){
        int l=0;
        for(auto it:mp){
            if(it.second%2==1){
                l++;
            }
        }
        if(l>1)return 0;
        return 1;
    }
    void dfs(TreeNode*root,map<int,int>& mp){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            mp[root->val]++;
            if(check(mp)){
                out++;
            }
            mp[root->val]--;
        }
        mp[root->val]++;

        dfs(root->left,mp);
        dfs(root->right,mp);
        mp[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int>mp;
        dfs(root,mp);
        return out;
    }
};