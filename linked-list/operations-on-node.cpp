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

void deleteNodeOnlyGivenPointerToNode(node* ptr) {
	node* temp = ptr->next;
	ptr->data = temp->data;
	ptr->next = temp->next;
	free(temp);
}

node* cloneLinkedListInReverse(node *temp) {
	node *reverse = NULL;
	while(temp != NULL) {
		insertAtStart(&reverse,temp->data);
		temp = temp->next;
	}
	return reverse;
}

int isPalindrome(node *head1,node *head2) {
	while(head1 != NULL && head2 != NULL)
		if(head1->data != head2->data)
			return 0;
		else {
			head1 = head1->next;
			head2 = head2->next;
		}
	return 1;
}

void recursiveReversePrintList(node *head) {
	if(head == NULL) return;
	recursiveReversePrintList(head->next);
	cout<<head->data<<" ->";
}

void removeDuplicatesFromSortedList(node *head) {
	if(head == NULL)
		return;

	node *next_ptr;

	while(head->next != NULL)
		if(head->data == head->next->data) {
			next_ptr = head->next->next;
			free(head->next);
			head->next = next_ptr;
		}
		else
			head = head->next;
}

void removeDuplicatesFromUnsortedList(node *head) {
	if(head == NULL)
		return;

	node *fixed = head, *moving;
	while(fixed != NULL && fixed->next != NULL) {
		moving = fixed;
		while(moving->next != NULL) {
			if(fixed->data == moving->next->data) {
				node *next_ptr = moving->next;
				moving->next = next_ptr->next;
				free(next_ptr);
			}
			else moving = moving->next;
		}
		fixed = fixed->next;
	}
}

void removeDuplicatesFromUnsortedListUsingHashing(node *head) {
	unordered_set<int> seen;
	node *current = head, *prev = NULL;
	while(current != NULL) {
		if(seen.find(current->data) != seen.end()) {
			prev->next = current->next;
			free(current);
		}
		else {
			seen.insert(current->data);
			prev = current;
		}
		current = prev->next;
	}
}

void swap(dataType *a, dataType *b) {
	dataType temp = *a;
	*a = *b;
	*b = temp;
}

void swapPairsIterative(node *head) {
	if(head == NULL) return;

	while(head != NULL && head->next != NULL) {
		swap(&(head->data),&(head->next->data));
		head = head->next->next;
	}
}

void swapPairsRecursive(node *head) {
	if(head == NULL || head->next == NULL) return;
	
	swap(&(head->data),&(head->next->data));
	swapPairsRecursive(head->next->next);
}

void moveLastToFirst(node **head) {
	if(*head == NULL) return;

	node *last = *head, *prev = NULL;

	while(last->next != NULL) {
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *head;
	*head = last;
}

node* intersectionOfTwoSortedListsUsingDummyNode(node *head1, node *head2) {
	node head, *tail = &head;
	head.next = NULL;
	while(head1 != NULL && head2 != NULL) {
		if(head1->data == head2->data) {
			insertAtEnd(&tail->next,head1->data);
			tail = tail->next;
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->data < head2->data)
					head1 = head1->next;
				else head2 = head2->next;
	}
	return head.next;
}

node* intersectionOfTwoSortedListsUsingPointerOfPointer(node *head1, node *head2) {
	node *head = NULL, **tail = &head;
	while(head1 != NULL && head2 != NULL) {
		if(head1->data == head2->data) {
			insertAtEnd(tail,head1->data);
			tail = &((*tail)->next);
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->data < head2->data)
					head1 = head1->next;
				else head2 = head2->next;
	}
	return head;
}

node* intersectionOfTwoSortedListsUsingRecursion(node *head1, node *head2) {
	if(head1 == NULL || head2 == NULL) return NULL;

	if(head1->data < head2->data)
		return intersectionOfTwoSortedListsUsingRecursion(head1->next, head2);

	if(head1->data > head2->data)
		return intersectionOfTwoSortedListsUsingRecursion(head1, head2->next);
	
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = head1->data;

	new_node->next = intersectionOfTwoSortedListsUsingRecursion(head1->next, head2->next);
	return new_node;
}

void deleteAlternateNodesIterative(node *head) {
	node *current = head, *next_ptr;

	while(current != NULL && current->next != NULL) {
		next_ptr = current->next;
		current->next = next_ptr->next;
		free(next_ptr);
		current = current->next;
	}
}

void deleteAlternateNodesRecursive(node *head) {
	if(head == NULL || head->next == NULL) return;

	node *next_ptr = head->next;
	head->next = next_ptr->next;
	free(next_ptr);
	deleteAlternateNodesRecursive(head->next);
}

void alternateSplitting(node *head, node **x, node **y) {
	if(head == NULL) return;
	int count = 1;
	while(head != NULL) {
		if(count%2 == 1)
			insertAtEnd(x, head->data);
		else insertAtEnd(y, head->data);
		count++;
		head = head->next;
	}
}

bool identicalLinkedListsIterative(node *x, node *y) {
	while(x != NULL && y != NULL) {
		if(x->data != y->data)
			return false;
		x = x->next;
		y = y->next;
	}
	
	return x == NULL && y == NULL;
}

bool identicalLinkedListsRecursive(node *x, node *y) {
	if(x == NULL && y == NULL) return true;

	if(x != NULL && y != NULL) 
		return (x->data == y->data) && identicalLinkedListsRecursive(x->next,y->next);
	return false;
}

void FrontBackSplit(node *head, node **x, node **y) {	
	if(head == NULL || head->next == NULL) {
		*x = head;
		*y = NULL;
		return;
	}

	node *slow = head, *fast = head->next;

	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	*x = head;
	*y = slow->next;
	slow->next = NULL;
}

void mergeSort(node **headRef) {
	node *head = *headRef;
	
	if(head == NULL || head->next == NULL) return;

	node *x, *y;
	FrontBackSplit(head,&x,&y);
	mergeSort(&x);
	mergeSort(&y);
	*headRef = iterativeMergeSort(x,y);
}

node* reverseInGroups(node *head, int n) {
	node *current = head, *prev = NULL, *next = NULL;
	for(int i = 0; current != NULL && i < n; i++) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	if(next != NULL)
		head->next = reverseInGroups(next,n);

	return prev;
}

node* alternateReverseInGroups(node *head, int n) {
	node *current = head, *prev = NULL, *next = NULL;
	for(int i = 0; current != NULL && i < n; i++) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	if(head != NULL)
		head->next = current;

	for(int i = 0; current != NULL && i < n-1; i++)
		current = current->next;
	
	if(current != NULL)
		current->next = alternateReverseInGroups(current->next,n);

	return prev;
}

void delNodes(node *head) {
	node *current = head, *maxnode = head;
	while(current != NULL && current->next != NULL)
		if(current->next->data < maxnode->data) {
			node *temp = current->next;
			current->next = temp->next;
			free(temp);
		}
		else {
			current = current->next;
			maxnode = current;
		}
}

void deleteNodesHavingGreaterValueOnRightSideIterative(node **head) {
	if(*head == NULL) return;

	iterativeReverse(head);
	delNodes(*head);
	iterativeReverse(head);
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

	deleteNodeOnlyGivenPointerToNode(head3);
	printList(head3);

	cout<<"1st Linked List : "<<endl;
	printList(head1);

	head2 = cloneLinkedListInReverse(head1);

	cout<<"2nd Linked List : "<<endl;
	printList(head2);

	int palindrome = isPalindrome(head1,head2);

	if(palindrome)
		cout<<"Palindrome"<<endl;
	else cout<<"Not Palindrome"<<endl;

	printList(head);
	recursiveReversePrintList(head);
	cout<<"NULL";

	node *head4 = NULL;
	insertAtStart(&head4, 'E');
	insertAtStart(&head4, 'D');
	insertAtStart(&head4, 'D');
	insertAtStart(&head4, 'C');
	insertAtStart(&head4, 'B');
	insertAtStart(&head4, 'B');
	insertAtStart(&head4, 'A');
	insertAtStart(&head4, 'A');
	insertAtStart(&head4, 'A');
	cout<<endl;
	printList(head4);
	removeDuplicatesFromSortedList(head4);
	printList(head4);

	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	printList(head);
	removeDuplicatesFromUnsortedList(head);
	printList(head);
	insertAtStart(&head, 'C');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'B');
	insertAtStart(&head, 'A');
	insertAtStart(&head, 'A');
	removeDuplicatesFromUnsortedListUsingHashing(head);

	printList(head);
	swapPairsIterative(head);
	printList(head);
	swapPairsRecursive(head);
	printList(head);

	moveLastToFirst(&head);
	printList(head);

	node *head11 = NULL;
	insertAtEnd(&head11, 'A');
	insertAtEnd(&head11, 'B');
	insertAtEnd(&head11, 'C');
	insertAtEnd(&head11, 'D');
	insertAtEnd(&head11, 'E');
	cout<<"1st linked list : "<<endl;
	printList(head11);
	node *head22 = NULL;
	insertAtEnd(&head22, 'C');
	insertAtEnd(&head22, 'D');
	insertAtEnd(&head22, 'E');
	cout<<"2nd linked list : "<<endl;
	printList(head22);
	node *head33 = intersectionOfTwoSortedListsUsingDummyNode(head11,head22);
	cout<<"Intersection using Dummy Node : "<<endl;
	printList(head33);
	node *head44 = intersectionOfTwoSortedListsUsingPointerOfPointer(head11,head22);
	cout<<"Intersection using Pointer of Pointer : "<<endl;
	printList(head44);
	node *head55 = intersectionOfTwoSortedListsUsingRecursion(head11,head22);
	cout<<"Intersection using Recursion : "<<endl;
	printList(head55);

	cout<<"Delete Alternate Nodes Iteratively : "<<endl;
	deleteAlternateNodesIterative(head55);
	printList(head55);
	cout<<"Delete Alternate Nodes Recursively : "<<endl;
	deleteAlternateNodesRecursive(head55);
	printList(head55);

	printList(head);
	cout<<"Alternate Splitting of Linked List : "<<endl;
	node *x = NULL, *y = NULL;
	alternateSplitting(head, &x, &y);
	printList(x);
	printList(y);

	cout<<"Iterative Method - "<<endl;
	if(identicalLinkedListsIterative(x,y))
		cout<<"Linked Lists are Identical"<<endl;
	else cout<<"Linked Lists are Not Identical"<<endl;

	cout<<"Recursive Method - "<<endl;
	if(identicalLinkedListsRecursive(x,y))
		cout<<"Linked Lists are Identical"<<endl;
	else cout<<"Linked Lists are Not Identical"<<endl;

	printList(head);
	mergeSort(&head);
	printList(head);

	cout<<"Reverse a Linked List in Groups of Size 3 : "<<endl;
	printList(reverseInGroups(head,3));

	printList(head);

	cout<<"Alternate Reverse a Linked List in Groups of Size 3 : "<<endl;
	printList(alternateReverseInGroups(head,3));

	printList(head11);
	cout<<"Delete Nodes Having Greater Value on Right Side : "<<endl;
	deleteNodesHavingGreaterValueOnRightSideIterative(&head11);
	printList(head11);

	return 0;
}