/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
    ListNode* temp = head;
    while(temp){
        if(temp->val==k){
            if(temp==head) head=head->next;
            
            ListNode* prev = temp->back;
            ListNode* front = temp->next;
            
            if(prev) prev->next = front;
            if(front) front->back = prev;
            
            delete temp;
           temp=front;
        }
        else temp=temp->next;
        }
       return head;
    }
};