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
    TreeNode* func(vector<int> &postorder,int postStart,int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> &mpp){
        if(inStart>inEnd || postStart < postEnd) return nullptr;
        TreeNode* node = new TreeNode(postorder[postStart]);
        int inRoot = mpp[node->val];
        int numsRight = inEnd - inRoot;
        node->left=func(postorder,postStart-numsRight-1,postEnd,inorder,inStart,inRoot-1,mpp);
        node->right = func(postorder,postStart-1,postStart-numsRight,inorder,inRoot+1,inEnd,mpp);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }   
        TreeNode* root = func(postorder,postorder.size()-1,0,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};