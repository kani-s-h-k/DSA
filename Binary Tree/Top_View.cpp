/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        vector<int> ans;
        if(!root) return ans;
        map<int,int> mpp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int level = p.second;
            if(mpp.find(level)==mpp.end()) mpp[level]=node->data;
            if(node->left) q.push({node->left,level-1});
            if(node->right) q.push({node->right,level+1});
        }
        for(auto it: mpp){
            ans.emplace_back(it.second);
        }
        return ans;
    }
};