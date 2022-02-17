#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

void Middle_ele(){
    Node *slow = head;
    Node *fast = head;

    if(head == NULL){
        cout<<"List is empty";
    }
    else{
        while (fast != NULL && fast ->next != NULL)
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }
    cout<<"Middle Element is: "<<slow ->data;
        
    }
}