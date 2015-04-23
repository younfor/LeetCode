/**
Sort a linked list in O(n log n) time using constant space complexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head)
    {
        if(head == NULL || head -> next == NULL)
            return head;
    
        ListNode *carry, *counter[64];
        int fill=0;
        while(head)
        {
            carry=head;
            head=head->next;
            carry->next=NULL;
            int i=0;
            while(i<fill&&counter[i]!=NULL)
            {
                carry=mergeTwoLists(carry,counter[i]);
                counter[i++]=NULL;
            }
            if(i==fill)
                fill++;
            swap(carry,counter[i]);
        }
        for(int i=1;i<fill;i++)
            counter[i]=mergeTwoLists(counter[i-1],counter[i]);
        return counter[fill-1];
        
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *h = new ListNode(0), *p;
    
        for(p = h; l1 != NULL && l2 != NULL; p = p -> next)
        {
            if(l1 -> val < l2 -> val)
                p -> next = l1, l1 = l1 -> next;
            else
                p -> next = l2, l2 = l2 -> next;
        }
    
        p -> next = l1 != NULL ? l1 : l2;
    
        return h -> next;
    }
};