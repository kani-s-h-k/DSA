#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* createLinkedList(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for(int i =1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverseLinkedList(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* removeHead(Node* head){
    if(head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* removeTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next!= nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* removeElementAtK(Node* head, int k){
    if(head == nullptr) return nullptr;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* removeElementK(Node* head, int k){
    if(head==nullptr) return nullptr;
    if(head->data == k){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp->data == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* insertElementBegin(Node* head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}
Node* insertElementEnd(Node* head, int val){
    Node* el = new Node(val);
    if(head==nullptr){
        head = el;
        return head;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next = el;
    return head;
}
int main() {
	vector<int> nums={1};
	Node* head = createLinkedList(nums);
	traverseLinkedList(insertElementEnd(head,2));
}
