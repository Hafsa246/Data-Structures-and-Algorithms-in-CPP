#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

Node* reverseKGroup(Node* head, int k) {
        Node *p, *c, *n;
        p = NULL;
        c = head;
        n = NULL;
        int cnt = 0;
        
        // Traverse the list and check if there are k nodes or not
        while(c && ++cnt < k) {
            c = c->next;
        }
        // Check if there is no enough nodes to reverse
        if(cnt<k) return head;   // Not enough k nodes, return head
        
        c=head;
        int count = 0;
        while(c != NULL && count < k){
            n = c->next;
            c->next = p;
            p = c; 
            c = n;
            count++;
        }
        
        
        if(n != NULL){
            head->next = reverseKGroup(n, k);
        }
        
        
        return p;
    }    