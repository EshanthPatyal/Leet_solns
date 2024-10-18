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
    vector<int>v;
    pair<int,bool> dfs(TreeNode*curr){
        if(!curr)return {0,1};
        auto l=dfs(curr->left);
        auto r=dfs(curr->right);
        if(l.second && r.second){
            int c=1+l.first+r.first;
            if(l.first==r.first){
                v.push_back(c);
                return {c,1};
            }
            return {c,0};
        }
        return {1+l.first+r.first,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        auto t=dfs(root);
        if(v.size()<k)return -1;
        sort(v.rbegin(),v.rend());
        return v[k-1];
    }
};