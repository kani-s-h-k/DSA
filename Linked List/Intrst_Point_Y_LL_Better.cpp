/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* collisionPoint(ListNode* t1, ListNode* t2, int d){
        ListNode* temp1 = t1, *temp2 = t2;
        while(d){
            d--;
            temp2=temp2->next;
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* tempA = headA, *tempB = headB;
       int n1=0,n2=0;
       while(tempA){
        n1++;
        tempA=tempA->next;
       }
       while(tempB){
        n2++;
        tempB=tempB->next;
       }
       if(n1<n2) return collisionPoint(headA,headB,n2-n1);
       else return collisionPoint(headB,headA,n1-n2);
    }
};