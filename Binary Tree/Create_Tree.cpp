#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int key){
            data=key;
            left=nullptr;
            right=nullptr;
        }
        
        TreeNode(int key, TreeNode* left1, TreeNode* right1){
            data=key;
            left=left1;
            right=right1;
        }
};

TreeNode* createTree(){
    int val;
    cout<<"Enter a node data (or -1 if there is no node) : ";
    cin>>val;
    cout<<endl;
    if(val==-1) return nullptr;
    TreeNode* root = new TreeNode(val);
    cout<<"Enter left child of "<<val<<": "<<endl;
    root->left=createTree();
    cout<<"Enter right child of"<<val<<": "<<endl;
    root->right = createTree();
    return root;
}

void inorderTraversal(TreeNode* root){
    if(root == nullptr) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = createTree();
    inorderTraversal(root);
    return 0;
}
