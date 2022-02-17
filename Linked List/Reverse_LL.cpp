#include<bits/stdc++.h>
#include"SLL_Insertion.cpp"
using namespace std;

void Reverse(){            //ITERATIVELY
    Node *p, *c, *n;           //p = previous, c = current, n = next
    p = NULL;
    c = head;
    
    while (c!=NULL)
    {
        n = c ->next;
        c ->next = p;
        p = c;
        c = n;
    }
    head = p;    
}

