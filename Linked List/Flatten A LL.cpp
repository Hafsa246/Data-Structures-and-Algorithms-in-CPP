#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* sortedMerge( Node* a, Node* b){
	// base cases

   if (a == NULL) {
       return b;
   }
   else if (b == NULL) {
       return a;
   }

    Node* result = NULL;
   if (a->data <= b->data){
       result = a;
       result->child = sortedMerge(a->child, b);
   }
   else {
       result = b;
       result->child = sortedMerge(a, b->child);
   }

   return result;
}

Node* flattenLinkedList(Node* head){

	if(head==NULL || head->next==NULL){
       return head;
   }

   Node* down=head;
   Node* right=flattenLinkedList(head->next);
   down->next=NULL;
   Node* ans=sortedMerge(down,right);

   return ans;
}