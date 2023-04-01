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
 // TC for this approach is O(n/2)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// TC for this approach is O(n)
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* curr=head;
//         int cnt=0;
//         while(curr!=NULL)
//         {
//             curr=curr->next;
//             cnt++;
//         }
//         ListNode* temp=head;
//      for(int i=1;i<=cnt/2;i++)
//    {
//        temp=temp->next;
//    }
//    return temp;
        
//     }
// };