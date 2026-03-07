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

vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.emplace_back(root->data);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }
    return ans;
}

vector<int> inorderTraversal(TreeNode* root){
    vector<int> inorder;
    if(root==nullptr) return inorder;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true){
        if(node){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()) break;
            node=st.top();
            st.pop();
            inorder.emplace_back(node->data);
            node=node->right;        
        }
    }
    return inorder;
} 

vector<int> postorderTraversal(TreeNode* root){
    vector<int> postorder;
    if(root==nullptr) return postorder;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root=s1.top();
        s1.pop();
        s2.push(root);
        if(root->left) s1.push(root->left);
        if(root->right) s1.push(root->right);
    }
    while(!s2.empty()){
        postorder.emplace_back(s2.top()->data);
        s2.pop();
    }
    return postorder;
}

int main() {
    TreeNode* root = createTree();
    vector<int> ans1 = preorderTraversal(root);
    for(auto it: ans1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> ans2 = inorderTraversal(root);
    for(auto it: ans2){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> ans3 = postorderTraversal(root);
    for(auto it: ans3){
        cout<<it<<" ";
    }
    return 0;
}
