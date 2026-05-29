/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode *temp1 = head1, *temp2 = head2;
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                res->child = temp1;
                res = temp1;
                temp1=temp1->child;
            }
            else{
                res->child = temp2;
                res = temp2;
                temp2=temp2->child;
            }
            res->next = nullptr;
        }
        while(temp1){
            res->child = temp1;
            res = temp1;
            temp1=temp1->child;
            res->next=nullptr;
        }
        while(temp2){
            res->child = temp2;
            res = temp2;
            temp2=temp2->child;
            res->next=nullptr;
        }
        return dummy->child;
    }
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        if(!head || head->next==nullptr) return head;

        ListNode* mergedHead = flattenLinkedList(head->next);
        return merge(head,mergedHead);
    }
};