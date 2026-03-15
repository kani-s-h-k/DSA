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
        void pathNode(TreeNode* root, vector<vector<int>> &ans,vector<int> &row){
            if(!root) return ;
            row.emplace_back(root->data);
            if(!root->left && !root->right) ans.emplace_back(row);
            else{
                pathNode(root->left,ans,row);
                pathNode(root->right,ans,row);
            }
            row.pop_back();
        }
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            vector<vector<int>> ans;
            vector<int> row;
            if(!root) return ans;
            pathNode(root,ans,row);
            return ans;
		}
};