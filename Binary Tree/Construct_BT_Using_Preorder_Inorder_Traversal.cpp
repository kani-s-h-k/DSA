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
    TreeNode* buildTreeFunc(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &mpp){
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int inRoot = mpp[node->val];
        int numsLeft = inRoot-inStart;
        node->left = buildTreeFunc(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mpp);
        node->right = buildTreeFunc(preorder, preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mpp);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root = buildTreeFunc(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};