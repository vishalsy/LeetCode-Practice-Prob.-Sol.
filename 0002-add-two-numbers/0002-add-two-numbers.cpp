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

    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode();
     
        ListNode* temp=ans;
        int c=0;
        int sum=0;

        
    
        while(l1!=NULL || l2!=NULL|| c){
            if(l1!=NULL){
                sum+=l1->val;
               l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            cout<<sum<<" ";
            sum+=c;
            int t=(sum)%10;
            c=sum/10;
            sum=0;
            ans->next=new ListNode(t);
            ans=ans->next;
            // cout<<t<<" ";
        
        }
        return temp->next;
    }
};