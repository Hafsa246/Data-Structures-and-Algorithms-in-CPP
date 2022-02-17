#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

// Approach 1 - Using vector

Node* sortList(Node* head) {
        Node *start = head;
        vector <int> result;
        
		// Push all the elements of the Linked List to a Vector
        while(start) 
        {
            result.push_back(start->data);
            start = start->next;
        }
        
		// Sort the Vector using the inbuilt function 
        sort(result.begin(), result.end());
        start = head;
        int i = 0;
        
		// Rewrite the data from first using the sorted vector values
        while(start)
        {
            start->data = result[i];
            start = start->next;
            i++;
        }
        
		// Voila! return the answer. 
        return head;
}


// Approach 2 - Using merge sort

Node* findmid(Node* head){
    Node* slow, *fast;
    slow = head;
    fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    // merge 2 sorted LL
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    
    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    
    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

Node* mergeSort(Node *head) {
    // base case
    if(head == NULL || head->next == NULL) return head;
    
    // break linkedlist into 2 halves after finding mid
    Node* mid = findmid(head);
    
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    
    // recursive calls
    left = mergeSort(left);
    right = mergeSort(right);
    
    // merging the lists together
    Node* res = merge(left, right);
    
    return res;
}