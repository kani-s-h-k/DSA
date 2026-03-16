/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void LCA(TreeNode* root,TreeNode* p,TreeNode* q,vector<vector<TreeNode*>> &paths,vector<TreeNode*> &path){
        if(paths.size()==2) return;
        if(!root) return;
        path.emplace_back(root);
        if(root==p || root==q){
            paths.emplace_back(path);
        }
        LCA(root->left,p,q,paths,path);
        LCA(root->right,p,q,paths,path);
        
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            vector<vector<TreeNode*>> paths;
            vector<TreeNode*> path;
            TreeNode* ans=nullptr;
            LCA(root,p,q,paths,path);
            if(paths.size()<2) return nullptr;
            int i = 0;
            while(i<paths[0].size() && i<paths[1].size()){
                if(paths[0][i]==paths[1][i]) ans=paths[0][i];
                else break;
                i++;
            }
            return ans;
    }
};