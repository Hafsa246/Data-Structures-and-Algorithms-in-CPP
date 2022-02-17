#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

Node* kReverse(Node* head, int k) {
    // Base call
    if(head == NULL){
        return NULL;
    }
    
    // Step 1: reverse first k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt = NULL;
    int cnt = 0;
    
    while(curr != NULL && cnt < k){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }
    
    // Step 2: Recursion
    if(nxt != NULL){
        head->next = kReverse(nxt, k);
    }
    
    // Step 3: return head of reversed list
    return prev;
}