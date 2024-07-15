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
    void recur(TreeNode* root,map<int,pair<int,int>>&mp){
        if(!root )return ;
        if(mp.find(root->val)!=mp.end()){
            int l=mp[root->val].first;
            int r=mp[root->val].second;

            if(l!=-1)root->left=new TreeNode(l);
            if(r!=-1)root->right=new TreeNode(r);
        }
        recur(root->left,mp);
        recur(root->right,mp);
        return ;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int,pair<int,int>>mp;
        set<int> st;
        for(auto it:d){
            if(it[2]==1){
                if(mp.find(it[0])==mp.end()){
                    mp[it[0]]={it[1],-1};
                }
                st.insert(it[1]);
                mp[it[0]].first=it[1];
            }
            else{
                if(mp.find(it[0])==mp.end()){
                    mp[it[0]]={-1,it[1]};
                }                
                st.insert(it[1]);
                mp[it[0]].second=it[1];
            }
        }
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        int root=-1;
        for(auto it:d){
            if(st.count(it[0])==0){
                root=it[0];
            }
        }
        TreeNode* ret=new TreeNode(root);
        recur(ret,mp);
        return ret;

    }
};