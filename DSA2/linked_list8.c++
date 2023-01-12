#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 

struct Node {
    int data;
    struct Node* next;
};
 

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 

void printList(struct Node* node)
{
   
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
 

Node* DeleteNodesfromBothEnds(struct Node** head_ref, int k)
{
    
    if (head_ref == NULL)
        return *head_ref;
 
    
    Node* firstPrev = NULL;
    Node* secondPrev = NULL;
 
    Node* fast = *head_ref;
 
    
    Node* head = *head_ref;
 
    
    for (int i = 0; i < k - 1; ++i) {
        firstPrev = fast;
        fast = fast->next;
    }
 
    Node* slow = *head_ref;
 
    
    while (fast != NULL && fast->next != NULL) {
        secondPrev = slow;
        slow = slow->next;
        fast = fast->next;
    }
 
    
    if (firstPrev == secondPrev) {
 
        if (firstPrev == NULL) {
 
            
            head = head->next;
        }
        else {
 
            
            firstPrev->next = firstPrev->next->next;
        }
    }
    else if (firstPrev != NULL && secondPrev != NULL
             && (firstPrev->next == secondPrev
                 || secondPrev->next == firstPrev)) {
 
        
        if (firstPrev->next == secondPrev)
            firstPrev->next = secondPrev->next->next;
 
        
        else
            secondPrev->next = firstPrev->next->next;
    }
    else {
 
        
        if (firstPrev == NULL) {
            head = head->next;
        }
        else {
 
            
            firstPrev->next = firstPrev->next->next;
        }
 
       
        if (secondPrev == NULL) {
            head = head->next;
        }
        else {
 
            
            secondPrev->next = secondPrev->next->next;
        }
    }
    return head;
}
 

int main(void)
{
 
    
    struct Node* head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
   
    int K = 3;
 
    printList(head);
 
   
    head = DeleteNodesfromBothEnds(&head, K);
 
    
    printList(head);
 
    
}