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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* start=NULL;
        ListNode* end=NULL;
        int pos=1;
            while(pos!=left)
            {
                prev=curr;
                curr=curr->next;
                pos++;
            }
                start=prev;
                end=curr;
                prev=curr;
                curr=curr->next;
                pos++;
            while((pos-1)!=right){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            pos++;
        }
        if(start!=NULL) start->next=prev;
        end->next=curr;
        if(start==NULL) return prev;
        return head;
    }
};