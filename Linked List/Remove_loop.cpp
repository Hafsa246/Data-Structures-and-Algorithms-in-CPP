#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

Node *removeLoop(Node *head)
{
    // Write your code here.
    Node *slow, * fast;
    slow = head;
    fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow==fast){
            break;
        }
    }
    
    if(slow == head){
        
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    
    else if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
    return head;
}
