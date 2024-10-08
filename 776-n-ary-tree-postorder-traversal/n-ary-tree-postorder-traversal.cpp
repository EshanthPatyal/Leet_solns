/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*>st;
        auto curr=root;
        vector<int> v;
        st.push(root);
        if(root==NULL)return v;
        while(!st.empty()){
                curr=st.top();
                st.pop();
                auto adj=curr->children;
                v.push_back(curr->val);
                for(int i=0;i<adj.size();i++){
                    st.push(adj[i]);
                }
        }
        reverse(v.begin(),v.end());
        return v;        
    }
};