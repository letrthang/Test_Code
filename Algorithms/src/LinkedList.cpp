/*
 * ============================================================================
 * Name        : LinkedList.cpp
 * Author      : Thang Le
 * Version     : Mar, 2015
 * Copyright   : www.letrungthang.blogspot.com
 * Description : Queue implementation
 * ============================================================================
*/


#include <iostream>
#include <cstdlib>

using namespace std;


struct Node {
int				data;
struct Node*	next;
};

/*
Build the list {1, 2, 3} in the heap and store
its head pointer in a local stack variable.
Returns the head pointer to the caller.
*/

Node* BuildOneTwoThree()
{
	 Node* head 	= 		NULL;
	 Node* second 	= 		NULL;
	 Node* third 	= 		NULL;

	// allocate 3 nodes in the heap
	head = (Node*)malloc(sizeof(Node));
	second = (Node*)malloc(sizeof(Node));
	third = (Node*)malloc(sizeof(Node));
	head->data = 1;
	// setup first node
	head->next = second;
	// note: pointer assignment rule
	second->data = 2;
	// setup second node
	second->next = third;
	third->data = 3;
	// setup third link
	third->next = NULL;
	// At this point, the linked list referenced by "head"
	// matches the list in the drawing.
	return head;
}

/*
Takes a list and a data value.
Creates a new link with the given data and pushes
it onto the front of the list.
The list is not passed in by its head pointer.
Instead the list is passed in as a "reference" pointer
to the head pointer -- this allows us
to modify the caller's memory.
*/
void Push(Node** headRef, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = *headRef;
	// The '*' to dereferences back to the real head
	*headRef = newNode; // bug ???
}

int main_ll()
{
	Node* head = BuildOneTwoThree();// suppose this returns the list {1, 2, 3}

	Push(&head, 0); // bug ???
	// note the &
	Push(&head, 13);
	// head is now the list {13, 0, 1, 2, 3}

	Node* current = head;
	while(current->next != NULL)
	{
		cout << current->data <<" \n";
		current = current->next;
	}
}
