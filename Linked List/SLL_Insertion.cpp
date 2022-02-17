#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node *head = NULL;

void insertBeg(int d){    
    
    //new node creation 
    Node* temp = new Node(d);
    temp->next = head;
    head = temp; 
}

void insertEnd(int d){
    Node* temp1 = new Node(d);
    if(head == NULL){
        head = temp1;
    }

    else{
        //temporary node to traverse 
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = temp1;
    }
}

void insertMid(int pos, int d){
    Node* temp = head;
    int cnt = 1;

    if(head == NULL or pos == 1){
        insertBeg(d);
        return;
    }

    if(temp->next == NULL){
        insertEnd(d);
        return;
    }

    while (cnt < pos-1)        //cause 3 pos me insert krna h to 2 pos tak traverse krna padega
    {
        temp = temp->next;
        cnt++;
    }

    //creating node
    Node* ins = new Node(d);
    ins->next = temp->next;
    temp->next = ins;
    
}

void print(){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    insertBeg(12);
    insertBeg(14);

    insertEnd(15);
    insertMid(4, 22);
    print();
}