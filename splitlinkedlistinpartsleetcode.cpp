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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        int equalnodes=cnt/k;
        int remainder=cnt%k;
        vector<ListNode*> ans;
        ListNode* originaltemp=head;
        while(k--)
        {
           ListNode* newhead=new ListNode(0);
           ListNode* temp=newhead;
           for(int i=0;i<equalnodes;i++)
           {
               temp->next=originaltemp;
               temp=temp->next;
               if(originaltemp) originaltemp=originaltemp->next;
           }
           if(remainder)
           {
               if(temp) temp->next=originaltemp;
               if(originaltemp) originaltemp=originaltemp->next;
               remainder--;
               temp=temp->next;
           }
            temp->next=NULL;
           ans.push_back(newhead->next);
        }
           return ans;
}
};