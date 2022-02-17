#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

Node *DetectNodeOfLoop(Node *head){
    Node *slow, *fast;
    slow = head;
    fast =  head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        return slow;    
        }
        
    }
    return NULL;  
}