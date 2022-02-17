#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

// Step 1 - reverse the two linked lists 
// Step 2 - add the numbers 
// Step 3 - reverse the ans


Node* reverse(Node* head){
        Node *p, *c, *n;
        p = NULL; c = head; n = NULL;
        
        while(c != NULL){
            n = c->next;
            c->next = p;
            p = c; 
            c = n;
        }
        return p;
}
Node* addTwoNumbers(Node* l1, Node* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        //sum, curr
        int s = 0, c = 0;
        
        // to assign a new node
        Node *temp;
        // to store the ans of single digits and then appending them to lists
        Node *res = NULL;
        // to traverse to the recently added ele
        Node *curr = NULL;
        
        while(l1 != NULL || l2 != NULL){
            s = c + (l1?l1->data:0) + (l2?l2->data:0);
            c = (s>=10)?1:0;
            s = s%10;
            
            temp = new Node(s);
            if(res == NULL) res = temp;
            else curr->next = temp;
            curr = temp;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(c>0){
            temp = new Node(c);
            curr->next = temp;
            curr = temp;
        }
        
        return reverse(res);
    }