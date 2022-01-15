
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

void addBeginning(Node** head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void addEnd(Node** head, int data){
    Node* newNode = new Node();
    Node *last = *head;

    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    return;
}

void addAfterSpecific(Node* prevNode, int data){
    if(prevNode==NULL){
        cout<<"NULL"<<endl;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;

}
void addBeforeSpecific(Node* aheadNode, Node* head, int data) {

	if(aheadNode == NULL) {
		std::cout << "NULL";
		return;
	}

	Node* current = head;
	while(current->next != aheadNode) {
		current = current->next;
	}



	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = aheadNode;
	current->next = newNode;
}

void deleteBeginning(Node** head){
    Node* temp = (*head)->next;
    (*head)->data = temp->data;
    (*head)->next = temp->next;
    delete temp;
}

void deleteEnd(Node* head){
    Node* current = head;
	while(current->next->next != NULL) {
		current = current->next;
	}

		current->next = NULL;
}

void deleteAfterSpecific(Node* prevNode){
    if(prevNode==NULL){cout<<"NULL";}
    prevNode->next = (prevNode->next)->next;

}

void print(Node *node){
    while(node != NULL){
        cout<<" "<<node->data;
        node=node->next;
    }
}

int main(){
    Node* head = NULL;

    addBeginning(&head,2);
    addEnd(&head,3);
    addBeginning(&head,1);
    addEnd(&head,4);
    addAfterSpecific(head->next,9);
    addBeforeSpecific(head->next, head, 50);
    print(head);

    deleteEnd(head);
    cout<<endl;
    print(head);
}
