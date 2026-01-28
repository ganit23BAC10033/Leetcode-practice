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
     
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        vector<int>arr;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int oddstart=0;
        int evenstart=1;
        temp=head;
        int k=0;
        while(temp!=nullptr && k<=arr.size()+1/2){
            k++;
            if(oddstart<arr.size()){
                temp->val=arr[oddstart];
                oddstart+=2;
               temp=temp->next;
            }
             
        }
        while(temp!=nullptr){
            if(evenstart<arr.size()){
                temp->val=arr[evenstart];
                evenstart+=2;
                temp=temp->next;
            }
        }
        return head;
         
    }
};