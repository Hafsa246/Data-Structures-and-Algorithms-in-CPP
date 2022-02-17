#include<bits/stdc++.h>
#include<map>
#include"SLL_Insertion.cpp"
using namespace std;


// Approach 1
int findLoop(Node *head){
    Node *slow, *fast;
    slow = head;
    fast = head;

    while (fast != NULL && fast ->next != NULL)
    {
        fast = fast ->next ->next;
        slow = slow ->next;

        if (slow == fast)
        {
            return 1;
        }
        
    }
return 0;    
}


// Approach 2
bool DetectLoop(Node* head){

    map<Node*, bool> visited;

    if(head == NULL) return 0;
    Node* temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
        
    }
    return 0;

}