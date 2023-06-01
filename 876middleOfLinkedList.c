/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *fast= head;
    struct ListNode *slow= head;

    while(1){
        if(fast==NULL || fast->next==NULL){
            break;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}