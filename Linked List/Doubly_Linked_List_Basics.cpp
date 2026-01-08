#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;
    
    Node(int data1, Node* back1, Node* next1){
        data = data1;
        back = back1;
        next = next1;
    }
    
    Node(int data1){
        data = data1;
        back = nullptr;
        next = nullptr;
    }
};
Node* createDLL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i=1;i<nums.size();i++){
        Node* temp =  new Node(nums[i],prev,nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp->next != nullptr){
        temp=temp->next;
    }
    prev = temp->back;
    temp->back = nullptr;
    prev->next = nullptr;
    delete temp;
    return head;
}

Node* deleteAtK(Node* head, int k){
    if(head == nullptr) return nullptr;
    int cnt =0;
    Node* temp = head;
    Node* prev = nullptr, *front = nullptr;
    while(temp){
        cnt++;
        if(cnt ==k) break;
        temp=temp->next;
    }
    prev = temp->back;
    front = temp->next;
    
    if(prev == nullptr && front == nullptr){
        delete temp;
        return nullptr;
    }
    else if(prev == nullptr){
        return deleteHead(head);
    } else if(front == nullptr){
        prev->next = nullptr;
        return deleteTail(head);
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next == nullptr;
        temp->back ==nullptr;
        delete temp;
    }
    return head;
}

Node* deleteNodeK(Node* head, int k){
    if(head == nullptr) return nullptr;
    Node* temp = head, *prev = nullptr, *front = nullptr;
    while(temp){
        if(temp->data == k) break;
        temp=temp->next;
    }
    prev = temp->back;
    front = temp->next;
    if(prev==nullptr && front == nullptr){
            delete temp;
            return nullptr;
    }
    else if(prev == nullptr){
        return deleteHead(head);
    } else if(front == nullptr){
        return deleteTail(head);
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back == nullptr;
        delete temp;
    }
    return head;
}

Node* insertBeforeHead(Node* head, int val){
    if(head == nullptr){
        Node* temp = new Node(val);
        return temp;
    }
    Node* temp = new Node(val,nullptr,head);
    head->back = temp;
    return temp;
}
Node* insertBeforeTail(Node* head, int val){
    if(head->next == nullptr) return insertBeforeHead(head,val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp=temp->next;
    }
    Node* prev = temp->back;
    Node* node = new Node(val,prev,temp);
    prev->next = node;
    temp->back = node;
    return head;
    
}

Node* insertBeforeKth(Node* head, int val, int k){
    if(k==1) return insertBeforeHead(head,val);
    Node* temp = head;
    int cnt =0;
    while(temp){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* node = new Node(val,prev,temp);
    prev->next = node;
    temp->back = node;
    return head;
}
void insertbeforeKNode(Node* node, int val){
    Node* prev = node->back;
    Node* el = new Node(val,prev,node);
    prev->next = el;
    node->back = el;
}
void traverseDLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main() {
    vector<int> nums = {1,2,3,4};
    Node* head = createDLL(nums);
    // insertbeforeKNode(head->next->next,15);
    traverseDLL(head);
    return 0;
}
