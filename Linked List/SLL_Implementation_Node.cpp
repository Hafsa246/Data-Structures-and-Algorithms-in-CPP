#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;              //implementation of node
    Node *next;


    //Constructor
    Node(int data){          //naya node assign krne
        this->data = data;
        this->next = NULL;
    }
};

int main()
{
    Node *node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

return 0;
}