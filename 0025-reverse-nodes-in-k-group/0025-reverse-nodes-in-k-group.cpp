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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* gprev = &dummy;

        while(true){
            ListNode *kth = gprev;

            for(int i = 0 ;i < k ; i++){
                kth = kth->next ;
                if(kth == nullptr){
                    return dummy.next;
                }
            }

                ListNode* gnext = kth->next;

                ListNode*prev = gnext;
                ListNode*curr = gprev->next;

                while(curr!= gnext){
                    ListNode* temp = curr->next;
                    curr->next = prev ;
                    prev = curr;
                    curr = temp;
                }

                ListNode* temp = gprev->next;
                gprev->next = kth ;
                gprev = temp;
            }
           
        return dummy.next;
    }
};