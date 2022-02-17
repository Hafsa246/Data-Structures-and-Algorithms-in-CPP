#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;


// Iterative Approach
Node* mergeTwoLists(Node* l1, Node* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        Node* head = l1;
        // Pointing the smallest data as head
        if(l1->data > l2->data){
            head = l2;
            l2 = l2->next;
        }
        else{
            l1 = l1->next;
        }
        
        Node* curr = head;
        while(l1 && l2){
            if(l1->data < l2->data){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(!l1) curr->next = l2;
        else curr->next = l1;
        
    return head;   
        
}

// Recursive Approach
Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        if(list1->data < list2->data){
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }//end if
        
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
}

Node* solve(Node* first, Node* second){
    
    //if only one ele is present in first list
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;
    
    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            //add node in between the first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            
            //update ptrs
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // curr1 and next1 ko aage badhana padega
            curr1 = next1;
            next1 = next1->next;
            
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* sortTwoLists(Node* first, Node* second)
{
    // Write your code here.
    if(first == NULL) return second;
    if(second == NULL) return first;
    
    if(first->data <= second->data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}