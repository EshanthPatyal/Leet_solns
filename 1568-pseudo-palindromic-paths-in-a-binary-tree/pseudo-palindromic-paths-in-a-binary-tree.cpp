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
    bool check(map<int,int>& mp){
        int l=0;
        for(auto it:mp){
            if(it.second%2==1)l++;
        }
        if(l>1)return 0;
        return 1;
    }
    int o=0;
    void dfs(map<int,int>& mp,TreeNode* r){
        if(!r)return;
        if(r->left==NULL && r->right==NULL){
            mp[r->val]++;
            if(check(mp)){
                o++;
            }
            mp[r->val]--;
        }
        mp[r->val]++;
        dfs(mp,r->left);
        dfs(mp,r->right);
        mp[r->val]--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> mp;
        dfs(mp,root);
        return o;
    }
};