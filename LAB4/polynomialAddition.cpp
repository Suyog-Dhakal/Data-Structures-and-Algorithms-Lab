#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int coef,expo;
    Node* next;
};

void insertBeginning(Node **link, int c, int e){
    Node* temp = new Node();
    temp->coef =c;
    temp->expo =e;
    temp->next = *link;
    *link = temp;
}

void insertEnd(Node **link, int c, int e){
    Node*temp = new Node();
    temp = *link;
    if(*link == NULL)
        insertBeginning(&(*link),c,e);
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }

        Node *p = new Node();
        p->coef = c;
        p->expo = e;
        p->next = NULL;
        temp->next = p;

    }
}

Node * addPolynomial(Node *poly1, Node *poly2){
    Node* poly3 = NULL;

     while(poly1 != NULL && poly2 != NULL){

        if(poly1->expo == poly2->expo){
            insertEnd(&poly3, poly1->coef+poly2->coef, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else{
            if(poly1->expo > poly2->expo){
                insertEnd(&poly3, poly1->coef, poly1->expo);
                poly1 = poly1->next;

            }else{

                insertEnd(&poly3, poly2->coef, poly2->expo);
                poly2 = poly2->next;
            }
        }
     }

     while(poly1 != NULL){
        insertEnd(&poly3,poly1->coef,poly1->expo);
        poly1 = poly1->next;
     }
     while(poly2 != NULL){
        insertEnd(&poly3,poly2->coef,poly2->expo);
        poly2 = poly2->next;
     }
     return poly3;
}

void display(Node *link){
    Node *t = new Node();
    t = link;
    while(t != NULL){
        cout<<t->coef<<"x"<<t->expo<<" + ";
        t=t->next;
    }
    cout<<endl;
}

int main()
{
    Node *start1,*start2,*start3;
    start1 = NULL;
    start2 = NULL;
    start3 = NULL;
    int x;

    insertEnd(&start1,3,8);
    insertEnd(&start1,5,7);
    insertEnd(&start1,8,4);
    cout<<"First polynomial is :";
    display(start1);

    insertEnd(&start2,3,7);
    insertEnd(&start2,5,6);
    insertEnd(&start2,8,2);
    cout<<"Second polynomial is :";
    display(start2);

    start3 = addPolynomial(start1,start2);
    cout<<endl;
    cout<<"Result of polynomial addition is :";
   display(start3);

}
