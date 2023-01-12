
#include <bits/stdc++.h>
#define max 1000000
using namespace std;


struct Node {
	int data;
	struct Node* next;
};


void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
			(struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


void Common(struct Node* head1,
			struct Node* head2, struct Node* head3)
{
	
	
	unordered_map<int, int> hash;
	
	struct Node* p = head1;
	while (p != NULL) {
		
		
		hash[p->data] = 1;
		p = p->next;
	}
	
	struct Node* q = head2;
	while (q != NULL) {
		
		
		if (hash.find(q->data) != hash.end())
			hash[q->data] = 2;
		q = q->next;
	}
	
	struct Node* r = head3;
	while (r != NULL) {
		if (hash.find(r->data) != hash.end() &&
			hash[r->data] == 2)
		
		
		hash[r->data] = 3;
		r = r->next;
	}

	
	for (auto x : hash) {
		

		if (x.second == 3)
			cout << x.first << " ";
	}
}


int main(void)
{

	
	struct Node* head1 = NULL;
	push(&head1, 20);
	push(&head1, 5);
	push(&head1, 15);
	push(&head1, 10);

	
	struct Node* head2 = NULL;
	push(&head2, 10);
	push(&head2, 20);
	push(&head2, 15);
	push(&head2, 8);
		
	
	struct Node* head3 = NULL;
	push(&head3, 10);
	push(&head3, 2);
	push(&head3, 15);
	push(&head3, 20);

	Common(head1, head2, head3);
	
	
}
