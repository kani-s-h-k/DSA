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
    int findLengthOfLoop(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        int timer=0;
        ListNode* temp = head;
        while(temp){
            if(mpp.find(temp)!=mpp.end()){
                return timer-mpp[temp];
            }
            mpp[temp]=timer;
            timer++;
            temp=temp->next;
        }
        return 0;
    }
};