/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next==nullptr) return head;
        vector<int> vec;
        ListNode* temp = head;
        while(temp!=nullptr && temp->next!=nullptr){
            vec.emplace_back(temp->val);
            temp=temp->next->next;
        }
        if(temp) vec.emplace_back(temp->val);
        temp = head->next;
        while(temp!=nullptr && temp->next!=nullptr){
            vec.emplace_back(temp->val);
            temp=temp->next->next;
        }
        if(temp) vec.emplace_back(temp->val);
        temp = head;
        int index = 0;
        while(temp){
            temp->val=vec[index];
            index++;
            temp=temp->next;
        }
        return head;
    }
};