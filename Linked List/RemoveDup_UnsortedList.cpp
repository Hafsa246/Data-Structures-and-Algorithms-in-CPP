#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

void RemoveDup(Node *head){
    map<int, int>m;
    Node *cur = head;
    m[cur->data] = 1;
    Node *prev = cur;
    cur = cur->next;

    while (cur != NULL)
    {
        if(m[cur->data]){
            prev->next = cur->next;
            free(cur);
        }
        else
        {
            m[cur->data] = 1;
            prev = cur;
        }
        cur = prev->next;    
    }

}


// Approach - 1 => TWO LOOPS

Node *removeDuplicates(Node *head)
{
    if(head==NULL){
        return NULL;
    }
    
    //non-empty LL => atleast ek node hai
    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        Node* prev = curr;
        while(prev->next!=NULL){
            if(curr->data == prev->next->data){
//                 Node* tempKaNext = temp->next;
                Node* duplicate = prev->next;
                prev->next = prev->next->next;
//                 temp->next = NULL;
                delete(duplicate);
            }
            else{
                prev = prev->next;
            }
        }
        curr=curr->next;
    }
    return head;
}


// APPROACH - 2 => Using Map method for implementation

Node * removeDuplicates( Node* head) 
    {
      map<int, bool>visited;
      Node* prev = head;
      Node* curr = head->next;
      
      visited[prev->data] = true;
      
      while(curr!=NULL){
          if(visited[curr->data] == true){
              prev->next = curr-> next;
              delete(curr);
          }
          else{
              visited[curr->data] = true;
              prev = prev->next;
          }
          curr = prev->next;
      }
      return head;
    }


