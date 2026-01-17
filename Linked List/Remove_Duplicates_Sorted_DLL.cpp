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

Node* s(Node* head){
    if(head==nullptr || head->next == nullptr) return head;
    Node* temp = head;
    while(temp && temp->next!=nullptr){
        Node* nextNode = temp->next;
        while(nextNode!=nullptr && nextNode->data == temp->data){
            Node* delNode = nextNode;
            nextNode=nextNode->next;
            delete delNode;
        }
        temp->next=nextNode;
        if(nextNode) nextNode->back = temp;
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
    sort(nums.begin(),nums.end());
    Node* head = createDLL(nums);
    traverseDLL(s(head));
}
