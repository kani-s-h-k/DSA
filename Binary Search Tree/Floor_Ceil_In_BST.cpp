/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
    void floorBST(TreeNode* root, int key,vector<int> &ans){
        int floor = -1;
            while(root){
                if(key==root->data){
                    floor = root->data;
                    ans.emplace_back(floor);
                    return;
                }
                if(key>root->data){
                    floor=root->data;
                    root=root->right;
                }
                else root=root->left;
            }
            ans.emplace_back(floor);
    }
    void ceilBST(TreeNode* root, int key, vector<int> &ans){
        int ceil = -1;
        while(root){
            if(key==root->data){
                ceil=root->data;
                ans.emplace_back(ceil);
                return;
            }
            if(root->data<key){
                root=root->right;
            }
            else{
                ceil=root->data;
                root=root->left;
            }
        }
        ans.emplace_back(ceil);
    }
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
            vector<int> ans;
			floorBST(root,key,ans);
            ceilBST(root,key,ans);
            return ans;
            
		}
};