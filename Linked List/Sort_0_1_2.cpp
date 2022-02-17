#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;


// Approach 1 - Replacing data with 0,1,2
Node* sortList(Node *head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else if(temp->data == 2){
            twoCount++;
        }
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
	return head;
}


// Approach 2 - without replacement by creating new sublists
void insertAtTail(Node* &tail, Node*curr){
    tail->next = curr;
    tail=curr;
}

Node* sortList(Node *head)
{
    
    // dummy nodes
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    
    // to traverse
    Node *curr = head;
    
    // create seperate list of 0,1,2
    while(curr != NULL){
        int value = curr->data;
        
        if(value == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1){
            insertAtTail(oneTail, curr);
        }
        if(value == 2){
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }
    
    // merge 3 sublists
    //1 list is non empty
    if(oneHead -> next != NULL){
        zeroTail ->next = oneHead->next;
    }
    // 1 is empty
    else{
        zeroTail ->next = twoHead->next;
    }
    oneTail -> next = twoHead->next;
    twoTail->next = NULL;
    
	// setup head
    head = zeroHead->next;
    
    // delete dummynodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}