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

void deleteNodeWithSpecifiedPostion(node **head, int position) {
	node *temp = *head;

	if(temp == NULL)
		return;

	if(position == 0) {
		*head = temp->next;
		free(temp);
		return;
	}

	for(int i = 0; temp != NULL && i < position - 1; i++)
		temp = temp->next;

	if(temp == NULL || temp->next == NULL)
		return;

	node *next = temp->next->next;
	
	free(temp->next);
	temp->next = next;
}

int iterativeLength(node *head) {
	int length = 0;
	node *temp = head;
	while(temp != NULL) {
		temp = temp->next;
		length++;
	}
	return length;
}

int recursiveLength(node *head) {
	if(head == NULL)
		return 0;
	return recursiveLength(head->next) + 1;
}

int iterativeSearch(node *head, dataType key) {
	node *temp = head;
	while(temp != NULL) {
		if(temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}

int recursiveSearch(node *head, dataType key) {
	if(head == NULL)
		return false;
	if(head->data == key)
		return true;
	return recursiveSearch(head->next,key);
}

void swapNodes(node **head, dataType x, dataType y) {
	if(x == y) 
		return;

	node *prevX = NULL, *currentX = *head;
	while(currentX != NULL && currentX->data != x) {
		prevX = currentX;
		currentX = currentX->next;
	}

	node *prevY = NULL, *currentY = *head;
	while(currentY != NULL && currentY->data != y) {
		prevY = currentY;
		currentY = currentY->next;
	}

	if(currentX == NULL || currentY == NULL)
		return;

	if(prevX != NULL)
		prevX->next = currentY;
	else *head = currentY;

	if(prevY != NULL)
		prevY->next = currentX;
	else *head = currentX;

	node *temp = currentY->next;
	currentY->next = currentX->next;
	currentX->next = temp;
}

dataType getNthNode(node *head, int n) {
	node *temp = head;
	int count = 0;
	while(temp != NULL) {
		if(count == n)
			return temp->data;
		count++;
		temp = temp->next;
	}

	return '0';
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
	deleteNodeWithSpecifiedPostion(&head,2);
	printList(head);
	cout<<"Length of Linked List using Iterative Method : "<<iterativeLength(head)<<endl;
	cout<<"Length of Linked List using Recursive Method : "<<recursiveLength(head)<<endl;
	cout<<"Search key in a Linked List using Iterative Method : "<<iterativeSearch(head,'C')<<endl;
	cout<<"Search key in a Linked List using Recursive Method : "<<recursiveSearch(head,'Z')<<endl;
	cout<<"Before Swapping Nodes : "<<endl;
	printList(head);
	swapNodes(&head,'B','C');
	cout<<"After Swapping Nodes : "<<endl;
	printList(head);
	cout<<"Get 2nd Node : "<<getNthNode(head,1)<<endl;
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
B->C->NULL
*/