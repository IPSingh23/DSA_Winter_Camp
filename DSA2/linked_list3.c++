#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *reverse(Node *head)
{
    Node *prev = NULL, *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        temp->next = prev;
        prev = temp;
    }
    return prev;
}
bool isPalindrome(Node *head, Node *reverseHead)
{
    Node *current1 = head, *current2 = reverseHead;
    while (current1 && current2)
    {
        if (current1->data != current2->data)
            return false;
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main(void)
{
    cout << "\nEnter number of values in linked list: ";
    int n;
    cin >> n;
    cout << "\nEnter the values: ";
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        char k;
        cin >> k;
        Node *temp = new Node(k);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    cout << "\nOriginal Linked list: ";
    printList(head);

    cout << "Reversed Linked list ";
    Node *reverseHead = reverse(head);
    printList(reverseHead);

    if (isPalindrome(head, reverseHead))
        cout << "Linked List is Palindrome";
    else
        cout << "Linked List is not Palindrome";

    
}