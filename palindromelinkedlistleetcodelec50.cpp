// approach 1 - make an array of the datas of the linked list and then check for palindrome but this approach takes up extra space so not a good one
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
 // approach 2 TC=O(n) and SC=O(1)
 // first find the middle node and then reverse the second half of the linked list and then compare the two halves 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true; // for single node
        if(head->next->next==NULL)  // for two nodes
        {
            if(head->val==head->next->val) return true;
            else return false;
        }
        // first finding middle of the linked list
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        // reversing the second half
        ListNode* prev=NULL;
        ListNode* curr=slow->next;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        slow->next=prev;
        // comparing the two halves
        ListNode* temp1=head;
        ListNode* temp2=slow->next;
        while(temp2!=NULL)
        {
          if(temp1->val!=temp2->val)
          {
              return false;
          }
          temp1=temp1->next;
          temp2=temp2->next;
        }
        return true;

    }
};