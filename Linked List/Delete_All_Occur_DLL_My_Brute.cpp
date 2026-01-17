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

Node* deleteAllOccurence(Node* head, int k){
    if(head==nullptr) return nullptr;
    Node* temp = head,*prev = nullptr;
    while(temp){
        if(temp->data == k){
            Node* prev=temp->back;
            while(temp!=nullptr && temp->data==k){
                temp=temp->next;
            }
            if(temp==nullptr){
                if(!prev) return nullptr;
                prev->next = nullptr;
                return head;
            }
            if(prev) prev->next = temp;
            else head = temp;
            temp->back=prev;
        }
        temp=temp->next;
    }
    return head;
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
    Node* head = createDLL(nums);
    traverseDLL(deleteAllOccurence(head,7));
}
