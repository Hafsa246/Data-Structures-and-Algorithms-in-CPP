#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

void insertAtTail(Node* &head, Node* &tail, int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
}


// Approach 1 - TC - O(N) SC - O(N)
Node *copyList(Node *head)
    {
        // Step 1 - Create A clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        // Step 2 - Create a map
        unordered_map<Node*, Node*> oldtoNewnode;
        
        Node* origNode = head;
        Node* cloneNode = cloneHead;
        
        while(origNode != NULL && cloneNode != NULL){
            oldtoNewnode[origNode] = cloneNode;
            origNode = origNode->next;
            cloneNode = cloneNode->next;
        }
        
        origNode = head;
        cloneNode = cloneHead;
        while(origNode != NULL){
            cloneNode->random  = oldtoNewnode[origNode->random];
            origNode = origNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
}

// Approach 2 - TC - O(N) SC - O(1)
Node* copyRandomList(Node* head) {
Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        // Step 2 - add clone nodes in between original lists
        Node* origNode = head;
        Node* cloneNode = cloneHead;
        while(origNode != NULL && cloneNode != NULL){
            Node* nxt = origNode->next;
            origNode->next = cloneNode;
            origNode = nxt;
            
            nxt = cloneNode->next;
            cloneNode->next = origNode;
            cloneNode = nxt;
        }
        
        // Step 3 - copy random ptr
        temp = head;
        while(temp !=NULL){
            if(temp->next != NULL){
                
                temp->next->random = temp->random? temp->random->next : temp->random;
                // if(temp->arb != NULL){
                //     temp->next->arb = temp->arb->next;
                // }
                // else{
                //     temp->next = temp->arb;
                // }
            }
            temp = temp->next->next;
        }
        
        // Step 4 - revert chnges in step 2
        origNode = head;
        cloneNode = cloneHead;
        while(origNode != NULL && cloneNode != NULL){
            origNode->next = cloneNode->next;
            origNode = origNode->next;
            
            if(origNode != NULL){
                cloneNode->next = origNode->next;
            }
            
            cloneNode = cloneNode->next;
        }
        
        // Step 5 - return ans
        return cloneHead;
    }