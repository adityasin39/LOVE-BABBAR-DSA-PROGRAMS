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
 // TC=O(n*klogk)
class Solution {
public:
struct comp
{
  bool operator()(ListNode* a, ListNode* b)
  {
      if(a->val>b->val) return true;
      return false;
  }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, comp> minHeap;
        int k=lists.size();
        for(int i=0;i<k;i++)
        {
            if(lists[i]) // if linked list is empty as in example 3
            minHeap.push(lists[i]);
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(!minHeap.empty())
        {
           if(head==NULL)
           {
               ListNode* temp=minHeap.top();
               head=temp;
               tail=temp;
               minHeap.pop();
               if(temp->next!=NULL)
               {
                   ListNode* nexttemp=temp->next;
                   minHeap.push(nexttemp);
               }
           }
           else
           {
               ListNode* temp=minHeap.top();
               tail->next=temp;
               tail=temp;
               minHeap.pop();
                if(temp->next)
               {
                   ListNode* nexttemp=temp->next;
                   minHeap.push(nexttemp);
               }
           }
        }
        return head;

    }
};