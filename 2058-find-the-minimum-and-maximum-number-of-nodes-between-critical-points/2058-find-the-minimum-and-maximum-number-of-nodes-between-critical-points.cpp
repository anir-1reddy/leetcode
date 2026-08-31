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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int prevc = -1;

        int minDist = INT_MAX;
        int maxDist = 0;

        int pos = 1 ;

        ListNode*prev = head;
        ListNode*curr = head->next;

        while(curr != NULL && curr->next != NULL){
            int nextval = curr->next->val;

            if((curr->val > prev->val && curr->val > nextval) || (curr->val < prev->val && curr->val < nextval)){
                
                if(first == -1){
                    first = pos;
                }

                else{
                    minDist = min(minDist , pos - prevc);
                    maxDist = max(maxDist , pos - first);
                }
                prevc = pos;
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }

        if(minDist == INT_MAX){
            return {-1,-1};
        }

        return {minDist , maxDist};
    }
};