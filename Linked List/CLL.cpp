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

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
Node* last = NULL;

// void insertInEmpty(int d){

//     //if list is not empty
//     if(last != NULL) return;

//     Node* temp = new Node(d);
//     last = temp;
//     last->next = last;   //linking to itself since it is a single node
// }

// void insertBeg(int d){

//     //if list is empty
//     if(last == NULL){
//         insertInEmpty(d);
//     }

//     Node* temp = new Node(d);
//     temp->next = last->next;
//     last->next = temp;
// }

// void insertEnd(int d){
//     if(last == NULL){
//         insertInEmpty(d);
//     }

//     Node* temp = new Node(d);
//     temp->next = last->next;
//     last->next = temp;
//     last = temp;
// }

// void insertMid(int ele, int d){
//     if(last == NULL){
//         insertInEmpty(d);
//     }

//     // else{
//     //     Node* curr = last;
//     //     while(curr->data != ele){
//     //         curr = curr->next;
//     //     }

//     //     Node* temp = new Node(d);
//     //     temp->next = curr->next;
//     //     curr->next = temp;
//     // }

//     Node* temp = new Node(d);
//     Node *p;
//     p = last->next;

//     do
//     {
//         if(p->data == ele){
//             temp->next = p->next;
//             p->next = temp;

//             if(p == last){
//                 last = temp;
//             }
//         }
//         p = p->next;
//     } while (p != last->next);

//     // cout<<ele<<" not present in the list"<<endl;
//     // return;
    
// }

void insertNode(int element, int d) {
    

    //empty list
    if(last == NULL) {
        Node* newNode = new Node(d);
        last = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = last;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}   
 
void deleteNode(int value) {

    //empty list
    if(last == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = last;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            last = NULL;
        }

        //>=2 Node linked list
        else if(last == curr ) {
            last = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

void print(){
    Node* temp = last;
    if(last == NULL){
        cout<<"List is Empty";
        return;
    }

    do
    {
        cout<<last->data<<" ";
        last = last->next;
    } while (last != temp);
    
    cout<<endl;
}

int main()
{
    // insertBeg(2);
    // insertBeg(1);
    // insertEnd(4);
    // insertMid(2,3);
    insertNode(1,2);
    insertNode(2,3);
    insertNode(3,4);
    deleteNode(4);
    print();

return 0;
}