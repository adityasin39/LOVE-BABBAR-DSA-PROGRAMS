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
 // check lee solution specially for multiplicity=2
class Solution {
public:
    int multiply(ListNode* head)
    {
        if(head==NULL) return 0;
        int value=2*head->val + multiply(head->next);
        head->val=value%10;
        return value/10;
    }
    ListNode* doubleIt(ListNode* head) {
        if(multiply(head)){
             ListNode* newhead=new ListNode(1);
             newhead->next=head;
             return newhead;
        }
        return head;
    }
};