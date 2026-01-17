#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* back;
    Node* next;
    
    Node(int data1){
        data = data1;
        back=nullptr;
        next=nullptr;
    }
    
    Node(int data1, Node* back1, Node* next1){
        data=data1;
        back=back1;
        next=next1;
    }
};

Node* createDLL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i =1;i<nums.size();i++){
        Node* temp = new Node(nums[i],prev,nullptr);
        prev->next = temp;
        prev=temp;
    }
    return head;
}
Node* findTail(Node* head){
    while(head->next!=nullptr){
        head=head->next;
    }
    return head;
}

vector<vector<int>> s(Node* head, int k){
    if(head==nullptr) return {};
    vector<vector<int>> ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data<right->data){
        vector<int>pair;
        if(left->data+right->data == k){
            pair.emplace_back(left->data);
            pair.emplace_back(right->data);
            ans.emplace_back(pair);
            left=left->next;
            right=right->back;
        }
        else if(left->data+right->data <k) left=left->next;
        else right = right->back;
    }
    return ans;
}
    

void traverseDLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    Node* head = createDLL(nums);
    vector<vector<int>> ans = s(head,4);
    for(auto it: ans){
        for(auto el: it){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
