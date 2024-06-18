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
class BSTIterator {
public:
    vector<TreeNode*>v;
    int i=1;
    BSTIterator(TreeNode* root) {
        v.push_back(NULL);
        recur(root);
    }
    void recur(TreeNode* root){
        if(!root)return ;
        recur(root->left);
        v.push_back(root);
        recur(root->right);
        return;
    }
    
    int next() {
        if(i<v.size())
            return v[i++]->val;
        return NULL;
    }
    
    bool hasNext() {
        if(i<v.size())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */