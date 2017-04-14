#include <bits/stdc++.h>

using namespace std;

typedef char dataType;
typedef struct node {
	dataType data;
	struct node *next;
}node;

void printList(node *node) {
	if(node == NULL) {
		cout<<"The linked list is empty"<<endl;
		return;
	}
	while(node != NULL) {
		cout<<node->data<<" -> ";
		node = node -> next;
	}
	cout<<"NULL"<<endl;
}

void insertAtStart(node **head, dataType data) {
	node *new_node = (node *)malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = *head;
	
	*head = new_node;
}

void insertAfter(node *prev_node, dataType data) {
	if(prev_node == NULL) {
		cout<<"Previous node cannot be NULL"<<endl;
		return;
	}

	node *new_node = (node *)malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = prev_node->next;
	
	prev_node->next = new_node;
}

void insertAtEnd(node **head, dataType data) {
	node *new_node = (node *)malloc(sizeof(node));

	new_node->data = data;
	new_node->next = NULL;

	if(*head == NULL) {
		*head = new_node;
		return;
	}

	node *last =  *head;

	while(last -> next != NULL) {
		last = last->next;
	}

	last->next = new_node;
}

void deleteNodeWithSpecifiedKey(node **head, dataType key) {
	node *temp = *head, *prev_node;
	
	if(temp != NULL && temp->data == key) {
		*head = temp->next;
		free(temp);
		return;
	}
	
	while(temp != NULL && temp->data != key) {
		prev_node = temp;
		temp = temp->next;	
	}

	if(temp == NULL) {
		cout<<"Key "<<key<<" not found in the Linked List"<<endl;
		return;
	}

	prev_node->next = temp->next;
	free(temp);
}

int main()
{
	node *head = NULL;
	insertAtStart(&head,'A');
	insertAtEnd(&head,'E');
	insertAfter(head,'C');
	insertAtStart(&head,'B');
	insertAtEnd(&head,'D');
	deleteNodeWithSpecifiedKey(&head,'D');
	deleteNodeWithSpecifiedKey(&head,'A');
	printList(head);
	return 0;
}

/*

A->NULL
A->E->NULL
A->C->E->NULL
B->A->C->E->NULL
B->A->C->E->D->NULL
B->A->C->E->NULL
B->C->E->NULL

*/