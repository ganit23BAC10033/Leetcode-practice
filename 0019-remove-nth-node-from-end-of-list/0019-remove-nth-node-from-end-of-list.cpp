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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }

        if(count == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int beforedeletednode = count - n;
        temp = head;
        int co = 1;

        while(co != beforedeletednode){
            co++;
            temp = temp->next; 
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};