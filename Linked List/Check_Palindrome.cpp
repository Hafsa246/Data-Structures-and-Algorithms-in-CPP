#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;


//Approach 1
bool check(vector<int> arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        while(s <= e){
            if(arr[s] != arr[e]){
                return 0;
            }
            s++;
            e--;
        }
    return 1;
}

bool isPalindrome(Node *head){

        vector<int> arr;
        Node *temp = head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
    return check(arr);
}


// Approach 2
Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow;
}

Node* reverse(Node* head){
        Node *p, *c, *n;
        p = NULL;
        c = head;
        n = NULL;
        
        while(c != NULL){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
}

bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next == NULL) return 1;
        
        // Step 1: Find Middle
        Node *middle = getMid(head);
        
        // Step 2: Reverse the second half of the list
        Node *temp = middle->next;
        middle->next = reverse(temp);
        
        // Step 3: Compare 2 halves
        Node *head1 = head;
        Node *head2 = middle->next;
        
        while(head2 != NULL){
            if(head1->data != head2->data) return 0;
            
            head1 = head1->next;
            head2 = head2->next;
        }
        
        // Step 4: repeat step 2
        temp = middle->next;
        middle->next = reverse(temp);
        
        return 1;
    }