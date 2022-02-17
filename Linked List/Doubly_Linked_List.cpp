#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
Node* head = NULL;
Node* tail = NULL;

void print(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertBeg(int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertEnd(int d){
    Node* temp = new Node(d);
    if(tail == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertMid(int pos, int d){
    Node* temp = head;

    if(head == NULL or pos == 1){
        insertBeg(d);
        return;
    }

    if(temp->next == NULL){
        insertEnd(d);
        return;
    }

    int cnt = 1;
    while (cnt < pos-1)
    {
        temp = temp->next;
        cnt++;
    }

    Node* ins = new Node(d);
    ins->next = temp->next;
    temp->next->prev = ins;
    temp->next = ins;
    ins->prev = temp;
    
}

void deleteNode(int pos){
    
    if(pos == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* previ = NULL;
        int cnt = 1;
        while(cnt < pos){
            previ = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        previ->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

insertBeg(2);
insertEnd(4);
insertEnd(6);
insertMid(2,8);
deleteNode(3);
print();

return 0;
}