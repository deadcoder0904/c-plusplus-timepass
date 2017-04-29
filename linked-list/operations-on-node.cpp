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

dataType getMiddleNode1(node *head) {
	if(head == NULL)
		return '0';
	int count = 0;
	node *temp = head;
	for(count = 0; temp != NULL; count++) 
		temp = temp->next;
	temp = head;
	for(int i = 0; i < count/2; i++)
		temp = temp->next;
	return temp->data;
}

dataType getMiddleNode2(node *head) {
	if(head == NULL)
		return '0';

	node *slow_ptr = head, *fast_ptr = head;

	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}

	return slow_ptr->data;
}

dataType getMiddleNode3(node *head) {
	if(head == NULL)
		return '0';
	
	node *mid = head;
	
	for(int count = 0; head != NULL; count++) {
		if(count & 1)
			mid = mid->next;
		head = head->next;
	}

	return mid->data;
}

dataType getNthNodeFromLast(node *head, int n) {
	node *temp = head;
	int len;
	
	for(len = 0; temp != NULL; len++)
		temp = temp->next;

	if(len < n)
		return '0';
	
	temp = head;
	for(int i = 0; i < len - n; i++)
		temp = temp->next;
	
	return temp->data;
}

void deleteLinkedList(node **head) {
	node *current = *head, *next;

	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

int frequencyOfNode(node *head, dataType key) {
	int count = 0;
	while(head != NULL) {
		if(head->data == key)
			count++;
		head = head->next;
	}
	return count;
}

void iterativeReverse(node **head) {
	node *prev = NULL, *current = *head, *next;
	
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	*head = prev;
}

void recursiveReverse(node **head) {
	node *first, *rest;
	
	if(*head == NULL)
		return;

	first = *head;
	rest = first->next;

	if(rest == NULL)
		return;

	recursiveReverse(&rest);

	first->next->next = first;
	first->next = NULL;

	*head = rest;
}

int detectLoop(node *head) {
	node *slow_ptr = head, *fast_ptr = head;
	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr == fast_ptr)
			return 1;
	}
	return 0;
}

node* iterativeMergeSort(node *x, node *y) {
	node *head = NULL;
	while(x != NULL && y != NULL) {
		if(x->data <= y->data) {
			insertAtEnd(&head,x->data);
			x = x->next;
		}
		else {
			insertAtEnd(&head,y->data);
			y = y->next;
		}
	}
	if(x == NULL) 
		while(y != NULL) {
			insertAtEnd(&head,y->data);
			y = y->next;	
		}
	else 
		while(x != NULL) {
			insertAtEnd(&head,x->data);
			x = x->next;	
		}	

	return head;
}

node* recursiveMergeSort(node *x, node *y) {
	node *head = NULL;

	if(x == NULL) return y;
	if(y == NULL) return x;

	if(x->data <= y->data) {
		head = x;
		head->next = recursiveMergeSort(head->next,y);
	}
	else {
		head = y;
		head->next = recursiveMergeSort(x,head->next);
	}
	return head;
}

void sortedInsert(node **head, dataType data) {
	if(*head == NULL) return;
	node *temp = *head;
	node* new_node = (node*) malloc(sizeof(node));
	new_node->data = data;
	while(temp != NULL && temp->next != NULL) {
		if(temp->next->data > data) {
			new_node->next = temp->next;
			temp->next = new_node;
			break;
		}
		temp = temp->next;
	}
}

int main()
{
	node *head = NULL;
	insertAtStart(&head,'A');
	insertAtEnd(&head,'E');
	insertAfter(head,'C');
	insertAtStart(&head,'B');
	insertAtEnd(&head,'D');
	printList(head);
	cout<<"Get Middle Node 1 : "<<getMiddleNode1(head)<<endl;
	cout<<"Get Middle Node 2 : "<<getMiddleNode2(head)<<endl;
	cout<<"Get Middle Node 3 : "<<getMiddleNode1(head)<<endl;
	cout<<"Get 2nd Node From Last : "<<getNthNodeFromLast(head,2)<<endl;
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
	deleteLinkedList(&head);
	printList(head);
	insertAtStart(&head, 'E');
	insertAtStart(&head, 'D');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'F');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	printList(head);
	iterativeReverse(&head);
	printList(head);
	recursiveReverse(&head);
	printList(head);
	cout<<"Node 'A' appeared "<<frequencyOfNode(head,'A')<<" times"<<endl;

	node *head1 = NULL;
	insertAtEnd(&head1, 'A');
	insertAtEnd(&head1, 'B');
	cout<<"1st linked list is :"<<endl;
	printList(head1);

	node *head2 = NULL;
	insertAtEnd(&head2, 'E');
	insertAtEnd(&head2, 'F');
	insertAtEnd(&head2, 'G');
	cout<<"2nd linked list is :"<<endl;
	printList(head2);

	cout<<"Iteratively Merged linked list is :"<<endl;
	node *head3 = iterativeMergeSort(head1, head2);
	printList(head3);

	cout<<"Recursively Merged linked list is :"<<endl;
	head3 = recursiveMergeSort(head1, head2);
	printList(head3);
	
	sortedInsert(&head3, 'D');
	printList(head3);
	
	return 0;
}