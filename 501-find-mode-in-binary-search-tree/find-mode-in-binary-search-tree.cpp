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
    void recur(TreeNode* root,map<int,int> & mp){
        if(!root)   return ;
        recur(root->left,mp);
        recur(root->right,mp);
        mp[root->val]++;
        return;
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        vector<int> v;
        recur(root,mp);
        int a=0;
        for(auto it:mp){
            a=max(a,it.second);
        }
        for(auto it:mp){
            if(it.second==a){
                v.push_back(it.first);
            }
        }

        return v;
    }
};