
#include <bits/stdc++.h>
using namespace std;


class Node
{
	public:
	int data;
	Node *next;
};


void deleteAlt(Node *head)
{
	if (head == NULL)
		return;

	
	Node *prev = head;
	Node *node = head->next;

	while (prev != NULL && node != NULL)
	{
		
		prev->next = node->next;
		delete(node); 
		
		prev = prev->next;
		if (prev != NULL)
			node = prev->next;
	}
}


void push(Node** head_ref, int new_data)
{
	
	Node* new_node = new Node();

	
	new_node->data = new_data;

	
	new_node->next = (*head_ref);

	
	(*head_ref) = new_node;
}


void printList(Node *node)
{
	while (node != NULL)
	{
		cout<< node->data<<" ";
		node = node->next;
	}
}


int main(void)
{
	
	Node* head = NULL;

	push(&head, 8);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
    push(&head, 7);
	cout<<"List before calling deleteAlt() \n";
	printList(head);

	deleteAlt(head);

	cout<<"\nList after calling deleteAlt() \n";
	printList(head);

	
}


