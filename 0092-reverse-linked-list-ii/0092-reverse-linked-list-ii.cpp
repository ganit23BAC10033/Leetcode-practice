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
    ListNode* reversepartoflist(ListNode* head,ListNode* leftp,ListNode* rightp,ListNode* leftpbefore,ListNode* rightpahead){
        ListNode*  temp=leftp;
        ListNode* prev=nullptr;
        while(temp!=rightpahead){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        if(leftpbefore!=nullptr){
            leftpbefore->next=prev;
        }
        else{
            head=prev;
        }
        leftp->next=rightpahead;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftp=nullptr;
        ListNode* rightp=nullptr;
        ListNode* rightpahead=nullptr;
        ListNode* leftpbefore=nullptr;
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            if(count==left-1) leftpbefore=temp;
            if(count==left){
                leftp=temp;
            }
            if(count==right){
                rightp=temp;
                rightpahead=temp->next;

                break;
            }
            temp=temp->next;
        }
        return reversepartoflist(head,leftp,rightp,leftpbefore,rightpahead);


    }
};