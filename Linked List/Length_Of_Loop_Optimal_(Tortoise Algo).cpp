/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    int findLength(ListNode* slow, ListNode* fast){
        int cnt =1;
        fast=fast->next;
        while(fast != slow){
            cnt++;
            fast=fast->next;
        }
        return cnt;
    }

    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head,*fast = head;
        while(fast!=nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast) return findLength(slow,fast);
        }
        return 0;
    }
};